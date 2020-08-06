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
const int T = 2e5+2;
const ll MOD = 998244353;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    ll r = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(x > n-k) v.pb(i), r += x;;
    }
    sort(v.begin(),v.end());
    ll ans = 1;
    for(int i = 1; i < v.size(); i++) ans = (ans*(v[i]-v[i-1]))%MOD;
    cout << r << " "<< ans << endl;
    return 0;
}

