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
        vector<int> v[2];
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            v[x&1].pb(i);
        }
        if(v[0].size()) {
            cout << 1 << endl << v[0][0] << endl;
        }
        else if(v[1].size() > 1) {
            cout << 2 << endl << v[1][0] << " " << v[1][1] << endl;
        } else cout << -1 << endl;
    }



    return 0;
}

