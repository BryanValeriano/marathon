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
const double eps = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    ll ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    bool ok = (bx-ax == cx && by-ay == cy);
    ok &= abs(hypot(ax-bx,ay-by)-hypot(bx-cx,by-cy)) <= eps;
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}

