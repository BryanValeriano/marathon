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
const ll MOD = 1e9+7;
const int T = 2e5+5;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll sum = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= MOD;
        sum = (sum+v[i])%MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        sum = (sum-v[i]+MOD)%MOD;
        ans = (ans + (v[i]*sum)%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}

