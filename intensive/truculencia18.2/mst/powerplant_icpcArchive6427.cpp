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
const int T = 210;
int pai[T + 10];
int peso[T + 10];

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
    for(int i = 0; i <= T; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int n,m,k;
    int cont = 0;
    while(tc--) {
        cin >> n >> m >> k;
        int a,b,c;
        int ans = 0;
        init();
        for(int i = 0; i < k; i++) {
            cin >> a;
            join(T, a);
        }
        priority_queue<node, vector<node>, greater<node> > pq;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            pq.push({a,b,c});
        }
        while(!pq.empty()) {
            node atual = pq.top();
            pq.pop();
            if(find(atual.x) != find(atual.y)) {
                join(atual.x, atual.y);
                ans += atual.dist;
            }
        }
        cout << "Case #" << ++cont << ": " << ans << endl;
    }
    return 0;
}

