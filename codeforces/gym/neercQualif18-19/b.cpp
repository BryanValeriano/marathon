#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 2e5 + 5;
ll cai[T];
ll fica[T];
ii v[T];


int main() {
    ios::sync_with_stdio(false);
    int n;
    ll h; 
    cin >> n >> h;

    for(int i = 0; i < n; i++) 
        cin >> v[i].fi >> v[i].se;

    for(int i = 1; i <= n; i++) {
        fica[i] = v[i-1].se - v[i-1].fi;
        cai[i] = v[i].fi - v[i-1].se;
        fica[i] += fica[i-1];
        cai[i] += cai[i-1];
    }
    cai[n] = INF;

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ll x = h + cai[i];
        ll fim = lower_bound(cai, cai + n + 1, x) - cai;
        ans = max(ans, fica[fim] - fica[i] + h);
    }

    cout << ans << endl;

    return 0;
}

