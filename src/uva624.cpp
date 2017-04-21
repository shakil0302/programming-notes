#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> res((1<<20)+1);
    int N, n;
    int w[21];
    while(cin >> N){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> w[i];
        }
        int mx = (1<<n)-1;
        res[0] = 0;
        int tr = 0;
        for(int i=1; i<=mx; i++){
            int tz = __builtin_ctz(i);
            res[i] = res[i&~(1<<tz)]+w[n-tz];
            if(res[i] <= N && res[i] > res[tr])
                tr = i;
        }
        for(int i=31; i>=0; i--){
            if(tr&(1<<i)) cout << w[n-i] << " ";
        }
        cout << "sum:" << res[tr] << endl;
    }

    return 0;
}
