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
        ll x,y; cin >> x >> y;
        if(x == 1 and x < y) cout << "NO" << endl;
        else if(x == 2 and y <= 3) cout << "YES" << endl;
        else if(x <= 3 and x < y) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}

