#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    ll a,b,c;
    while(tc--) {
        bool flag = true;
        cin >> a >> b >> c;
        ll x,y,z;
        for(x = -2e6; x <= 2e6 and x*x <= c and flag; x++) {
            for(y = -2e3; y <= 2e3 and (x*x) + (y*y) + ((a-(x+y)) * (a-(x+y))) <= c and flag; y++) {
                z = a - (x+y);
                if(x != y and x != z and y != z and x+y+z == a and
                        x*y*z == b and x*x + y*y + z*z == c) {
                    cout << x << " " << y << " " << z;
                    flag = false;
                }
            }
        }
        if(flag) cout << "No solution." << endl;
    }
    return 0;
}

