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

bool insideC(int dx, int dy, int r, bool fuk) {
    int euc = dx*dx + dy*dy, rsq = r*r;
    return (fuk? euc <= rsq : euc < rsq);
}

bool oneInside(int r, int x, int y, int ri) {
    bool ok = 0;
    ok |= insideC(x,y,r,0);
    ok |= insideC(x,y+ri,r,0);
    ok |= insideC(x,y-ri,r,0);
    ok |= insideC(x+ri,y,r,0);
    ok |= insideC(x-ri,y,r,0);
    return ok;
}

bool inside(int r, int x, int y, int ri) {
    bool ok = 1;
    ok &= insideC(x,y,r,1);
    ok &= insideC(x,y+ri,r,1);
    ok &= insideC(x,y-ri,r,1);
    ok &= insideC(x+ri,y,r,1);
    ok &= insideC(x-ri,y,r,1);
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    int r,d;
    cin >> r >> d;
    int ans = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y,ri; cin >> x >> y >> ri;
        bool a = oneInside(r-d,x,y,ri);
        bool b = inside(r,x,y,ri);
        //cout << a << " " << b << endl;
        ans += ((!a) and b);
    }
    cout << ans << endl;
    return 0;
}

