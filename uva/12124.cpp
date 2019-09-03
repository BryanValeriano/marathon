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

int n,t;
unordered_map<string, vector<ii> > comps;

bool check(int mini) {
    int price = 0;

    for(auto g : comps) {
        bool flag = 0;
        int tmp = INF;

        for(auto v : g.se) {
            if(v.fi >= mini) {
                tmp = min(v.se,tmp);
                flag = 1;
            }
        }

        if(!flag) return 0;
        price += tmp;
    }

    return (price <= t);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string s,u;
    int p,q;

    while(tc--) {
        cin >> n >> t;
        comps.clear();

        for(int i = 0; i < n; i++) {
            cin >> s >> u >> p >> q;
            comps[s].pb(mk(q,p));
        }

        for(unordered_map<string, vector<ii> >::iterator it = comps.begin(); it != comps.end(); ++it) 
            sort(it->se.begin(), it->se.end());

        int l = 0;
        int r = 1e9;
        int ans = 0;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }

        cout << ans << endl;
    }
    return 0;
}

