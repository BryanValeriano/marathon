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
        ll n,m;
        cin >> n >> m;
        if(!m) cout << 0 << endl;
        else if(m >= n/2) {
            cout << ((n*(n+1))>>1) - (n-m) << endl;
        } else {
            ll comp = m*2;
            ll rest = n - comp;
            cout << ((comp*(comp+1))>>1)-(comp-m) + comp*rest << endl;
        }
    }
    return 0;
}

