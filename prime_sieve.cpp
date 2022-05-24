#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int prime[100000001];

void prime_sieve(int n){
    fill(prime, prime + n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= int(sqrt(n)); i++)
        if (prime[i] == 1)
            for (int j = i * i; j <= n; j += i)
                    prime[j] = 0;
}

int main(){
    int n;
    cin >> n;
    prime_sieve(n);
    for (int i = 2; i <= n; i++)
        if (prime[i] == 1)
            cout << i << endl;
    return 0;
}
