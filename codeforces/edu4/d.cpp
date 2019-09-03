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

vii v;

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    else if(a.se != b.se) return a.se > b.se;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k,x,y; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.eb(x,1), v.eb(y,-1);
    }
    sort(v.begin(), v.end(), cmp);

    vector<int> ans;
    ll acum = 0;
    bool flag = true;

    for(auto x : v) {
        acum += x.se;
        if(acum >= k and flag) { ans.pb(x.fi), flag = false; }
        if(acum < k and !flag) { ans.pb(x.fi), flag = true; }
    }

    cout << ans.size()/2 << '\n';
    for(int i = 0; i+1 < ans.size(); i += 2) cout << ans[i] << " " << ans[i+1] << '\n';

    return 0;
}

