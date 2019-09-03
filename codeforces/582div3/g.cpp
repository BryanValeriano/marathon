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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 2;
int pai[T];
ll peso[T];

void init() {
    for(int i = 1; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

struct edg {
    int a,b,p;

    bool operator < (const edg &y) const {
        if(p !=  y.p) return p < y.p;
        else if(b != y.b) return b < y.b;
        return a < y.a;
    }
};

vector<edg> v;
ll ans[T];
ll at = 0;

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    at -= (peso[x] * (peso[x]-1))/2;
    at -= (peso[y] * (peso[y]-1))/2;
    peso[x] += peso[y];
    at += (peso[x] * (peso[x]-1))/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    init();
    cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.pb({a,b,c});
    }

    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        v.pb({i,INF,a});
    }

    sort(v.begin(), v.end());


    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i].b == INF) ans[v[i].a] = at;
        else join(v[i].a,v[i].b);
    }

    for(int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

