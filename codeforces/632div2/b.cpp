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
const int T = 1e5+5;
int a[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int mask = 0;
        bool ok = 1;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x < a[i]) ok &= (mask&1);
            else if(x > a[i]) ok &= (bool)(mask&2);
            mask |= (a[i] < 0? 1 : a[i] > 0? 2 : 0);
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}

