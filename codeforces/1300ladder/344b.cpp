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
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z;
    for(x = 0; x <= a; x++) {
        y = b - x;
        z = c - y;
        if(x >= 0 and y >= 0 and z >= 0)
            if(x + y == b and y + z == c and z + x == a) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
    }
    cout << "Impossible" << endl;
    return 0;
}

