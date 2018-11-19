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
const int T = 1e6 + 10;

struct node {
    int x, y, dis;
    
    bool operator < (const node &b) {
        if(dis != b.dis) return dis < b.dis;
        return false;
    }
};

node aresta[T];
int pai[T], peso[T], qtd[T];

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] > peso[y]) pai[y] = x;
    else if(peso[x] < peso[y]) pai[x] = y; 
    else {
        pai[x] = y;
        peso[y]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++)
            pai[i] = i;
        for(int i = 1; i <= m; i++) 
            cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
        sort(aresta+1, aresta+m+1);

        int tanque = 0;
        for(int i = 1; i <= m; i++) {
            if( find(aresta[i].x) != find(aresta[i].y) ) {
                join(aresta[i].x, aresta[i].y);
                tanque = max(tanque, aresta[i].dis);
            }
        }
        cout << tanque << endl;
    }


    return 0;
}

