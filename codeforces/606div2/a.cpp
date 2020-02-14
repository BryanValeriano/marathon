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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        ll ini = 9;
        int ans = 0;

        while(ini <= x) {
            ans += 9;
            ini *= 10ll;
            ini += 9;
        }

        ini /= 9;
        ans += x/ini;
        cout << ans << endl;
    }
    return 0;
}

