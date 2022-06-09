#include <iostream>
#include <fstream>

using namespace std;

ifstream fi ("quick_sort_inp.txt");
ofstream fo ("quick_sort_out.txt");

int n, arr[1000000];

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

void out(){
    for (int i = 0; i < n; i++)
        fo << arr[i] << " ";
    return;
}

int main(){
    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> arr[i];
    quickSort(0, n-1);
    out();
    return 0;
}