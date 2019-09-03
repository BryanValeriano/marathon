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
const ll lim = (1LL << 33);

int n,m;
int dv[15];

ll monta(int x) {
    ll lcm = 0;
    int z = __builtin_popcount(x);

    if(z == 1) return n / dv[(int)log2(x)];

    for(int i = 0; i < m; i++) {
        if(x & (1 << i)) {
            if(lcm == 0) lcm = dv[i];
            else lcm = (lcm*dv[i])/__gcd(lcm,(ll)dv[i]);
        }
    }

    return n/lcm;
}

int calc() {
    int gol = (1 << m) - 1;
    ll ans = 0;

    for(int i = 1; i <= gol; i++) {
        if(__builtin_popcount(i) & 1) ans += monta(i);
        else ans -= monta(i);
    }

    return (int)ans;
}

int main() {
    while(~scanf("%d ", &n)) {
        scanf("%d\n", &m);
        for(int i = 0; i < m; i++) scanf("%d", &dv[i]);
        printf("%d\n", n - calc());
    }
    return 0;
}

