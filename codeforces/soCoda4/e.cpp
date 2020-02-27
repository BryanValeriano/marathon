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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 10;
ll pos[T];
vii v;

int main() {
    ios_base::sync_with_stdio(false);
    int m; cin >> m;
    int size = 0;
    ll real = 0;

    while(m--) {
        ll op,x,y; cin >> op >> x;
        if(op == 1) {
            v.eb(x,0);
            pos[size++] = real;
            real++;
        } else {
            cin >> y;
            x--;
            if(v.size() + (x*y) > T) v[x].se += y;
            else for(int i = 0; i <= x; i++) v.eb(v[i].fi,0);
        }
    }



    return 0;
}

