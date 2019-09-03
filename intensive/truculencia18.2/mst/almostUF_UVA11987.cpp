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
const int T = 1e5 + 10;
int pai[2*T];
int peso[2*T];
int sum[2*T];

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = pai[T + i] = T + i; 
        peso[i] = peso[T + i] = 1;
        sum[i] = sum[T + i] = i;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] <= peso[y]) swap(x,y);
    pai[y] = x;
    sum[x] += sum[y];
    peso[x] += peso[y];
}

void remove(int x) {
    int xx = find(x);
    peso[xx]--;
    sum[xx] -= x;
    pai[x] = x;
    peso[x] = 1;
    sum[x] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, oper, a, b;
    while(cin >> n >> q) {
        init();
        while(q--) {
            cin >> oper;
            if(oper == 1) {
                cin >> a >> b;
                join(a,b);
            }
            else if(oper == 2) {
                cin >> a >> b;
                if(find(a) != find(b)) {
                    remove(a);
                    join(a,b);
                }
            } else {
                cin >> a;
                cout << peso[find(a)] << " " << sum[find(a)] << endl;
            }
        }
    }
    return 0;
}

