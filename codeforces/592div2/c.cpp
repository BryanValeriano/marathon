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
    ll n,p,d,w;
    cin >> n >> p >> w >> d;

    for(ll y = 0; y <= min(w-1,n); y++) {
        ll z = p - (y*d);
        if(z < 0) break;
        if(z % w == 0 and z/w + y <= n) {
            cout << z/w << " " << y << " " << (n - (z/w) - y) << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}

