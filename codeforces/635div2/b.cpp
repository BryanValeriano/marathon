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
        int x,n,m; cin >> x >> n >> m;
        while(n and x/2 + 10 <= x) n--, x = x/2 + 10;
        cout << (x/10+(x%10?1:0) <= m? "YES" : "NO") << endl;
    }
    return 0;
}

