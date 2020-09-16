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
const int T = 3e3+2;
int g[T][T];
int v[T];

ll solve(int n) {
    ll ans = 0;
    for(int j = n-3; j >= 0; j--) {
        for(int l = j+2; l < n; l++) g[v[j+1]][v[l]]++;
        for(int i = j-1; i >= 0; i--) ans += (ll)g[v[i]][v[j]];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = 0;
        for(int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n) << endl;
    }
    return 0;
}

