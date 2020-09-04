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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,m; cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                char c; cin >> c;
                ans += (c == 'D' and i == n-1);
                ans += (c == 'R' and j == m-1);
            }
        cout << ans << endl;
    }
    return 0;
}

