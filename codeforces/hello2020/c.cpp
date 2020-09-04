#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e8+2;
ll fat[N];

ll calc(ll i, ll n, ll m) {
    ll ans = ((n-(i-1))*(n-(i-1))) % m;
    ans = (ans * (ll)fat[i]) % m;
    ans = (ans * (ll)fat[n-i]) % m;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    fat[0] = 1;
    for(int i = 1; i <= n; i++) fat[i] = ((ll)i*(ll)fat[i-1])%m;
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
        ans = (ans + calc(i,n,m)) % m;
    cout << ans << endl;
    return 0;
}

