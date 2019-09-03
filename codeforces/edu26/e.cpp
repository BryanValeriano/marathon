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

ll a,b;
vector<ll> primes;
const int T = 60;
bool vis[T];

void pre(ll x) {
    for(ll i = 2; i*i <= x; i++)  
        while(x % i == 0) x /= i, primes.pb(i);
    if(x != 1) primes.pb(x);
}

void pre2(ll x) {
    for(int i = 0; i < primes.size(); i++)
        if(x % primes[i] == 0) vis[i] = 1, x /= primes[i];
}

ll check(ll b, ll best, ll passo, int id) {
    return(b - (b/(primes[id]*passo)*primes[id]*passo)) / passo;
}
     
ll solve(ll a, ll b) {
    if(b == 0) return 0;
    if(a == 1) return b;
    ll passo = __gcd(a,b);
    ll best = INF;
    int id = 59;

    for(int i = 0; i < primes.size(); i++) {
        ll tent = check(b,best,passo,i);
        if(tent < best and ! vis[i]) {
            best = tent;
            id = i;
        }
    }

    vis[id] = 1;
    if(best == INF) return b/passo; 
    return best + solve(a, b - best*passo);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    pre(a);
    pre2(__gcd(a,b));
    cout << solve(a,b) << endl;
    return 0;
}

