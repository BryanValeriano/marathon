#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e6 + 10;
ii v[T];

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    else if(a.se != b.se) return a.se < b.se;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    for(int i = 0; i < n; i++) 
        cin >> v[i].fi >> v[i].se;
    
    sort(v, v+n, cmp);

    vii ans;
    vii tmp;
    for(int i = 0; i+(k-1) < n; i++) 
        if(v[i].se >= v[i+(k-1)].fi) tmp.eb(v[i+(k-1)].fi, v[i].se);
   
    for(int i = 0; i < tmp.size();) {
        int j = i;
        int last = tmp[i].se;
        while(j < tmp.size() and tmp[i].se >= tmp[j].fi) last = max(last,tmp[j].se), j++;
        ans.eb(tmp[i].fi,last);
        i = j;
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x.fi << " " << x.se << endl;

    return 0;
}

