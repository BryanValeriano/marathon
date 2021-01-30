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
    freopen("katryoshka.in","r",stdin);
    int t; cin >> t;
    int cont = 0;
    while(t--) {
        int a,b,c; cin >> a >> b >> c;
        int x = min({a,b,c});
        int ans = x;
        a -= x, b -= x, c -= x;
        x = min(a/2,c);
        ans += x;
        a -= 2*x, c -= x;
        cout << "Case " << ++cont << ": " << ans << endl;
    }
    return 0;
}

