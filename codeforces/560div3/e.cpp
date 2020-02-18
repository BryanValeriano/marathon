#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<ll,vector<ll>> pq;
    priority_queue<ll,vector<ll>, greater<ll>> pq2;

    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        x *= (i+1) * (n-i);
        pq.emplace(x);
    }

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        pq2.emplace(x);
    }

    ll ans = 0;

    while(pq.size()) {
        ll a = pq.top();
        pq.pop();
        ll b = pq2.top();
        pq2.pop();

        a %= MOD;
        b %= MOD;
        ans = ((a*b)%MOD + ans) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}

