/*
    ** 1 second == 1/3600 hours.
*/
#include <cstdio>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
//input
#define ri(x) scanf("%d", &x);
#define rll(x) scanf("%lld", &x);
#define r64d(x) scanf("%I64d", &x);
//debug
//constants + types
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//helper macros + algorithm
#define rep(i,a,b) for(i=a; i<b; i++)
#define per(i,b,a) for(i=b; i>a; i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
//containers
#define pb push_back
#define mp make_pair
#define fi first
#define se second

//geometry
typedef pair<int, int> point;
typedef pair<int, int> vec;
vec operator+(const vec &a, const vec &b){
    return mp(a.fi+b.fi, a.se+b.se);
}
vec operator-(const point &a, const point &b){
    return mp(b.fi-a.fi, b.se-a.se);
}
int operator*(const vec &a, const vec &b){
    return a.fi*b.fi+a.se*b.se;
}
int operator^(const vec &a, const vec &b){
    return a.fi*b.se-a.se*b.fi;
}
double dist(const point &a, const point &b){
    return sqrt(sq(b.fi-a.fi)+sq(b.se-a.se));
}
double raydist(const point &a, const point &b, const point &c){
    return ((b-a)^(c-a))/dist(a, b);
}
double segdist(const point &a, const point &b, const point &c){
    if((b-a)*(c-a) > 0) return dist(b, c);
    else if((a-b)*(c-b) > 0) return dist(a, c);
    else return raydist(a, b, c);
}
double area(vector<point> poly){
    double res = 0;
    int i;
    rep(i, 1, sz(poly)-1){
        res += (poly[i]-poly[0])^(poly[i+1]-poly[0]);
    }
    return abs(res/2);
}
//get started
