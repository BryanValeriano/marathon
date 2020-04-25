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
const int T = 82;
ll v[T][T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k; cin >> n >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> v[i][j];

    ll ans = LLONG_MAX;
    k /= 2;
    for(int i = 2; i <= n; i++)
        ans = min(ans, v[1][i]*k + v[i][1]*k);

    cout << ans << endl;
    return 0;
}

