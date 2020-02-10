#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 5;
int a[T];

int32_t main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int n,m;
    while(tc--) {
        cin >> n >> m;

        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[x] = i;
        }

        int ans = 0;
        int mytop = 1;

        for(int i = 1; i <= m; i++) {
            int x; cin >> x;
            if(mytop >= a[x]) ans++;
            else {
                ans += (a[x]-i)*2 + 1;
                mytop = a[x];
            }
        }

        cout << ans << endl;
    }



    return 0;
}

