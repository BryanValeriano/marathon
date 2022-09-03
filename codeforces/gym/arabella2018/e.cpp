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
const int T = 1e4+2;
char v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,m,k,x;
        int ans = 0;
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) cin >> v[i];
        while(m--) {
            char c; cin >> c;
            if(c == 'A') { k = n+1; continue; }
            cin >> x;
            ans += (v[x-1] == 'S' && k >= x);
            k = max(k,x);
        }
        cout << ans << endl;
    }
    return 0;
}

