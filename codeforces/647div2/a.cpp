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
const ll LIM = 2e18;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b; cin >> a >> b;
        int ans = 0;
        if(a > b) swap(a,b);
        ll tmp = b/a;
        if(a*tmp == b) {
            int ans = 0;
            while(tmp%8==0) ans++, tmp /= 8;
            while(tmp%4==0) ans++, tmp /= 4;
            while(tmp%2==0) ans++, tmp /= 2;
            cout << (tmp == 1? ans : -1) << endl;
        } else cout << -1 << endl;
    }
    return 0;
}

