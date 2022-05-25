#include <iostream>
#include <math.h>

using namespace std;

int prime[10000001];

void primeOnSegment(int L, int R){
    int range = R - L + 1;
    fill(prime, prime + range, 1);
    for (int i = 2; i <= sqrt(R); i++)
        for (int j = max(i * i, int(L / i) * i); j <= R; j += i)
            if ((j - L) >= 0 && prime[j - L] == 1)
                prime[j - L] = 0;
    if (L == 1)
        prime[0] = 0;
}

int main(){
    int L, R;
    cin >> L >> R;    
    primeOnSegment(L, R); 
    for (int i = 0; i < R - L + 1; i++)
        if (prime[i] == 1)
            cout << i + L << endl;
    return 0;
}