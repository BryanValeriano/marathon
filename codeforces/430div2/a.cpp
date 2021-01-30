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
const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    ll l,r,x,y,k;
    cin >> l >> r >> x >> y >> k;
    for(ll i = x; i <= y; i++) {
        if(i*k >= l and i*k <= r) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

