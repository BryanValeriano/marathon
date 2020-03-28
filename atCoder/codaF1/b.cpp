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
const int T = 1e5 + 3;

map<ll,ll> freq;
ll v[T];
ll n,MOD;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> MOD;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = (v[i] + v[i-1]) % MOD;
        freq[v[i]]++;
    }

    freq[0]++;
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        freq[v[i-1]]--;
        ans += (ll)freq[v[i-1]];
    }

    cout << ans << endl;

    return 0;
}

