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

const int T = 1105;
ll v[T][T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        int n,m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> v[i][j], v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];

        ll ans = v[1][1];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans = max(ans, v[n][m] - v[i-1][m] - v[n][j-1] + v[i-1][j-1]);

        cout << ans << endl;
    }

    return 0;
}

