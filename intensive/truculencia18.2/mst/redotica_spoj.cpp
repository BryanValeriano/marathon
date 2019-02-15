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
const int T = 110;
int pai[T];
int peso[T];

struct node {
    int u,v,c;

    bool operator < (const node &b) const {
        if(c != b.c) return c < b.c;
        return false;
    } 
    bool operator > (const node &b) const {
        if(c != b.c) return c > b.c;
        return false;
    }   
};

priority_queue< node, vector<node>,  greater<node> > pq;

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    if(peso[y] == peso[x]) peso[x]++;
}

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}

void read(int m) {
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({a,b,c});
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int cont = 0;
    while(n or m) {
        init();
        read(m);
        cout << "Teste " << ++cont << endl;
        while(!pq.empty()) {
            node atual = pq.top();
            pq.pop();
            if(find(atual.u) != find(atual.v)) {
                join(atual.u, atual.v);
                cout << min(atual.u,atual.v) << " " << max(atual.u, atual.v) << endl;
            }
        }
        cin >> n >> m;
        if(n or m) cout << endl;
    }


    return 0;
}

