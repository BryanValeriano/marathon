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
int a,b,c;

bool check(int x, int y, int z) {
    if(x != y and x != z and y != z and x*y*z == b and x+y+z == a and x*x + y*y + z*z == c) {
        cout << min(x,y) << " " << max(x,y) << " " << z << endl;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> a >> b >> c;
        int x1,y1,z1,z2,z3;
        bool flag = true;
        int z;
        for(int x = 1; x*x <= c and flag; x++) {
            for(int y = 1; y*y <= c - (x*x) and flag; y++) {
                x1 = -x; y1 = -y;
                z1 = a - (x1 + y1);
                z2 = a - (x + y1);
                z3 = a - (x1 + y);
                z = a - (x+y);
                if(check(x,y,z)) { flag = false; break; }
                else if(check(x1,y1,z1)) { flag = false; break; }
                else if(check(x,y1,z2)) { flag = false; break; }
                else if(check(x1,y,z3)) { flag = false; break; }
            }
        }
        if(flag) cout << "No solution." << endl;
    }
    return 0;
}

