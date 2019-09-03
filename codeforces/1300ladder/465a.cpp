#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return a.fi < b.fi;
}

bool cmp2(const pair<int,int>&a, const pair<int,int>&b) {
    if(a.sec != b.sec) return a.sec < b.sec;
    else return a.fi < b.fi; 
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector< pair<int,int> >row;
    vector< pair<int,int> >row2;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        row.pb(mk(a,b));
        row2.pb(mk(a,b));
    }
    sort(row.begin(), row.end(), cmp);
    sort(row2.begin(), row2.end(), cmp2);
    for(int i = 0; i < n; i++) {
        if(row[i].fi != row2[i].fi) {
            cout << "Happy Alex" << endl;
            return 0;
        }
    }
    cout << "Poor Alex" << endl;    

    return 0;
}

