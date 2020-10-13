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
        int n; cin >> n;
        int x = 0, y = 0;
        bool ans = 1;
        while(n--) {
            int xx,yy; cin >> xx >> yy;
            ans &= (yy-y <= xx-x and yy >= y and xx >= x);
            x = xx, y = yy;
        }
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}

