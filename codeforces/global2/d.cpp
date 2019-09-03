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
const ll INF = 2e18;

const int T = 1e5 + 3;
ll v[T];
vector<ll> passo;
vector<ll> acum;
int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);

    ll ini = 0;

    passo.pb(0);
    for(int i = 1; i <= n; i++) {
        passo.pb(v[i] - v[i-1]);
        if(passo[i]) ini++;
        passo[i] = max(passo[i] - 1, 0LL);
    }

    passo.pb(INF);
    sort(passo.begin(), passo.end());

    acum.pb(passo[0]);

    for(int i = 1; i <= n+1; i++) {
        acum.pb(passo[i]);
        acum[i] += acum[i-1];
    }

    int q; cin >> q;

    while(q--) {
        ll a,b;
        cin >> a >> b;
        ll x = b-a;
        ll mid = lower_bound(passo.begin(), passo.end(), x) - passo.begin();
        while(passo[mid] > x and mid > 0) mid--; 
        ll great = acum.size() - mid - 1;
        cout << ini + acum[mid] + great*x << endl; 
    }

    return 0;
}

