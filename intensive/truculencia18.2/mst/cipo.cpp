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
const int T = 1010;
int n, m;
int pai[T];
int peso[T];

struct node {
    int x,y,dist;

    bool operator > (const node &b) const {
        if(dist != b.dist) return dist > b.dist;
        return false;
    }
};

int find(int x) {
    return(x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    if(peso[x] == peso[y]) peso[x]++;
}

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}


int main() {
    ios::sync_with_stdio(false);
    int cont = 0;
    while(cin >> n >> m) {
        if(cont != 0) cout << endl;
        init();
        int a,b,c;
        priority_queue<node, vector<node>, greater<node> >pq;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            pq.push({a,b,c});
        }
        int z = 0;
        ll ans = 0;
        while(!pq.empty() and z < n-1) {
            node atual = pq.top();
            pq.pop();
            if(find(atual.x) != find(atual.y)) {
                join(atual.x, atual.y);
                ans += atual.dist;
                z++;
            }
        }
        cout << "Instancia " << ++cont << endl;
        cout << ans << endl;
    }
    return 0;
}

