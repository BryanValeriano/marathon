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
map <int,int> saldo;
map <int,int> abertos;
vector<ii> v;
vector<ii> ve;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        v.clear();
        ve.clear();
        saldo.clear();
        abertos.clear();

        for(int i = 1; i <= n; i++) {
            int x,y; cin >> x >> y;
            v.eb(x,y);
            ve.eb(x,1);
            ve.eb(y+1,-1);
            ve.eb(y,0);
        }

        sort(v.begin(),v.end());
        sort(ve.begin(),ve.end());

        int tot = 0;
        int ok = 0;
        for(ii z : ve) {
            tot += max(0,z.se);
            ok += z.se;
            abertos[z.fi] = tot;
            saldo[z.fi] = ok;
        }

        int ans = 0;
        for(ii z : v) {
            ans = max(ans, saldo[z.fi] + (abertos[z.se]-abertos[z.fi]));
        }

        cout << n-ans << endl;
    }

    return 0;
}

