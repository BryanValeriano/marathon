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
map<ll,ll> city;
map<ll,ll> compress;
vector<tuple<ll,ll,ll>> que;
int lim;
const int T = 2e5;
int bit[T];

void pre() {
    int n,q; cin >> n >> q;
    compress[0] = 1;
    for(int i = 0; i < n; i++) {
        ll z = 0;
        ll x,y; cin >> x >> y;
        if(x == 1) {
            cin >> z;
            city[y] += z;
            compress[city[y]] = 1;
        } else {
            compress[y] = 1;
        }
        que.eb(x,y,z);
    }
    int aux = 0;
    for(auto x : compress) {
        aux += x.se, compress[x.fi] = aux;
    }
    for(auto x : city) city[x.fi] = 0;
}

void update(int pos, int val) {
    for(; pos < T; pos+=(pos&(-pos))) bit[pos] += val;
}

int rsq(int pos) {
    int sum = 0;
    for(; pos; pos-=(pos&(-pos))) sum += bit[pos];
    return sum;
}

int query(int a, int b) {
    return rsq(b) - rsq(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();

    for(auto e : que) {
        ll x,y,z;
        tie(x,y,z) = e;
        if(x == 1) {
            if(city[y]) {
                update(compress[city[y]], -1);
            }
            city[y] += z;
            update(compress[city[y]], 1);
        } else {
            cout << query(compress[y], T-1) << endl;
        }
    }
    return 0;
}

