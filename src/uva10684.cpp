#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, dp[10001], m;

    while(cin >> n, n){
        dp[0] = 0;
        m = -100000;
        for(int i=1; i<=n; i++){
            cin >> x;
            dp[i] = max(dp[i-1]+x, x);
            m = max(m, dp[i]);
        }
        if(m > 0)
            cout << "The maximum winning streak is " << m << "." << endl;
        else
            cout << "Losing streak." << endl;
    }
    return 0;
}
