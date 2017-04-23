#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int day, month, year;

    Person(string n, int d, int m, int y){
        name = n;
        day = d;
        month = m;
        year = y;
    }
    bool operator<(const Person ot) const {
        if(year == ot.year){
            if(month == ot.month){
                return day < ot.day;
            } else {
                return month < ot.month;
            }
        } else {
            return year < ot.year;
        }
    }
};

int main()
{
    int n;
    string name;
    int d, m, y;
    vector<Person> pt;

    cin >> n;
    while(n--){
        cin >> name >> d >> m >> y;
        pt.push_back(Person(name, d, m, y));
    }
    sort(pt.begin(), pt.end());
    cout << pt.rbegin()->name << endl;
    cout << pt.begin()->name << endl;

    return 0;
}
