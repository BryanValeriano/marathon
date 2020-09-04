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
const int T = 205;
bool v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        memset(v,0,sizeof v);
        int n,x;
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            v[a] = 1;
        }

        int ans = 0;
        for(int i = 1; i < T; i++) {
            if(v[i]) ans = i;
            else if(x) ans = i, x--;
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}

