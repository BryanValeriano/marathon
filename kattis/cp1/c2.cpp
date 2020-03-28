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
unordered_map<ll,vii> bag;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            bag[v[i] + v[j]].eb(i,j);

    bool sol = 0;
    ll ans = -1e18;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i == j or v[i] <= ans) continue;
            for(ii ok : bag[v[i]-v[j]])
                if(ok.fi != i and ok.fi != j and ok.se != i and ok.se != j)
                    sol = 1, ans = max(ans,v[i]);
        }

    if(sol) cout << ans << endl;
    else cout << "no solution" << endl;

    return 0;
}

