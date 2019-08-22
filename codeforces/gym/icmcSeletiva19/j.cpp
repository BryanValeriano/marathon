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

vector<ll> v;
int n;

bool isPrime(ll x) {
    if(x == 1) return false;
    for(ll i = 2; i*i <= x; i++) if(x%i == 0) return 0;    
    return 1;
}

ll dist(int pos) {
    ll x = v[pos];
    ll y = v[pos];

    while(!isPrime(x)) x++;
    while(y > 2 and !isPrime(y)) y--;
    if(y < 2) y = 2;

    ll ans1 = 0;
    ll ans2 = 0;
    for(int i = 0; i < n; i++) ans1 += abs(v[i]-x), ans2 += abs(v[i]-y);

    return min(ans1,ans2); 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    cout << min(dist(n/2), dist(((n/2) + 1)%n) ) << endl;

    return 0;
}

