#include <iostream>
#include <fstream>

using namespace std;

ifstream fi ("binary_search_inp.txt");
ofstream fo ("binary_search_out.txt");

int n, arr[1000000], x;

void quickSort(int left, int right){
    int mid = arr[(left + right) / 2], i = left, j = right;
    if (left >= right)
        return;
    while (i < j){
        while (arr[i] < mid)
            i++;
        while (arr[j] > mid)
            j--;
        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(left, j);
    quickSort(i, right);
}

int binarySearch(int x, int left, int right){
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        if (x < arr[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}

int main(){
    fi >> n >> x;
    for (int i = 0; i < n; i++)
        fi >> arr[i];
    quickSort(0, n - 1);
    fo << binarySearch(x, 0, n - 1);
    return 0;
}