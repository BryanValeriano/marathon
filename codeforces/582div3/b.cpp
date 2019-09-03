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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int x;
        int ans = 0;
        for(int i = 0; i < n; i++) cin >> v[i];
        v[n] = INF;
        for(int i = n-1; i >= 0; i--) {
            x = v[i];
            v[i] = min(v[i],v[i+1]);
            if(x > v[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

