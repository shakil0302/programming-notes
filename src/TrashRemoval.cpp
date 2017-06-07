#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, x, y;
pii points[100];
int leftmost, start, last;
double ans;

int cross(int i, int j, int k){
    pii AB, AC;
    AB.first = points[j].first-points[i].first;
    AB.second = points[j].second-points[i].second;
    AC.first = points[k].first-points[i].first;
    AC.second = points[k].second-points[i].second;
    int cross = AB.first * AC.second - AB.second * AC.first;
    return cross;
}
int sq(int x){
    return x*x;
}
double dist(int i, int j){
    return sqrt(sq(points[j].first-points[i].first)+sq(points[j].second-points[i].second));
}

int main()
{
    int tc = 1;
    while(cin >> n, n){
        for(int i=0; i<n; i++){
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }
        leftmost = 0;
        for(int i=1; i<n; i++){
            if(points[i].first < points[leftmost].first || points[i].first == points[leftmost].first &&
               points[i].second > points[leftmost].second) leftmost = i;
        }
        last = start = leftmost;
        ans = 1e15;
        do {
            int temp = -1;
            for(int i=0; i<n; i++){
                if(i == last) continue;
                if(temp == -1)
                    temp = i;
                else if(cross(last, i, temp) < 0)
                    temp = i;
            }
            //process last, temp
            //cout << points[temp].first << " " << points[temp].second << endl;
            double mdistance = 0;
            for(int i=0; i<n; i++){
                if(last == i || temp == i) continue;
                mdistance = max(mdistance, abs(cross(last, temp, i)/dist(last, temp)));
            }
            ans = min(ans, mdistance);
            last = temp;
        } while(start != last);
        printf("Case %d: %.2f\n", tc++, ans+1e-9);
    }

    return 0;
}
