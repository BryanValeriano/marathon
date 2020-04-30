#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3 + 2;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int>v(n);
    vector<bool>vis(T);
    vector<int> ans;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = n-1; i >= 0; i--)
        if(!vis[v[i]]) vis[v[i]] = 1, ans.pb(v[i]);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

