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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 5e3 + 5;
ll n,m;
vector<ll> v[T];
ll pior[T];

int main() {
    ios::sync_with_stdio(false);
    int a,b;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].pb(b);
    }

    for(ll i = 1; i <= n; i++) {
        ll last = INF;
        ll corner = INF;
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] > i) last = min(last, v[i][j]);
            else corner = min(corner, v[i][j]);
        }

       
        ll t = v[i].size();
        if(last != INF) pior[i] = (t - 1LL)*n + last-i;
        else if(corner != INF) pior[i] = t*n - (i-corner);
        else pior[i] = 0;
    }


    for(ll i = 1; i <= n; i++) {
        ll ans = 0;
        for(ll j = 1; j <= n; j++) ans = max( ans, pior[j] + (pior[j]? (j >= i? j-i : n - (i-j)) : 0));
        cout << ans << " ";
    }

    cout << endl;

    return 0;
}

