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
#define loop(x) for(int i = 0;i < x;i++)

int mdc(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return mdc(b, a % b);
}

struct frac {
    int a, b;
    frac(int x, int y) {
        int m = mdc(abs(x), abs(y));
        a = x / m * (y / abs(y));
        b = abs(y / m);
    }
    bool operator<(frac& f) {
        return a * f.b < b * f.a;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    frac minx(0, 1), maxx(1, 1);
    int a, b, la, lb;
    cin >> la >> lb;
    bool ans = true;
    if (la < lb) swap(la, lb);
    loop(n - 1) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        int p = la - lb + b - a, q = b - lb;
        if (p) {
            frac aux(q, p);
            if (p > 0) minx = (minx < aux ? aux : minx);
            else maxx = (maxx < aux ? maxx : aux);
        }
        la = a;
        lb = b;
    }
    if (maxx < minx or minx.a < 0 or maxx.a > maxx.b) ans = false;
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}

