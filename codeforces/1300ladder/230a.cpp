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

int main() {
    ios::sync_with_stdio(false);
    ll s;
    int n; cin >> s >> n;
    vector< pair<int,int> >row;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        row.pb(mk(a,b));
    }
    sort(row.begin(), row.end(), cmp);
    for(int i = 0; i < n; i++) {
        if(s > row[i].fi) 
            s += row[i].sec;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}

