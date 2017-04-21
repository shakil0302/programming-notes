#include <bits/stdc++.h>
using namespace std;

bool isPrime[38];
int num[17];
bool used[17];
int n;
void print_ring(int m){
    //cout << m << endl;
    if(m == n+1){
        if(!isPrime[num[n]+1]) return;
        cout << num[1];
        for(int i=2; i<=n; i++)
            cout << " " << num[i];
        cout << endl;
        return;
    }
    for(int d = 1; d<=n; d++){
        if(!used[d] && isPrime[num[m-1]+d]){
            used[d] = true;
            num[m] = d;
            print_ring(m+1);
            used[d] = false;
        }
    }
}
int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    fill(isPrime, isPrime+38, false);
    for(int i=0; i<12; i++)
        isPrime[primes[i]] = true;

    bool first = true;
    int k = 0;
    while(cin >> n){
        k++;
        if(!first) cout << endl;
        first = false;
        printf("Case %d:\n", k);
        num[1] = 1;
        fill(used, used+17, false);
        used[1] = true;
        print_ring(2);
    }

    return 0;
}
