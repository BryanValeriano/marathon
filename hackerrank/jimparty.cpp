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
const int T = 1e5 + 3;
int n, m, q;
int amigo[T];
vector<int> jogo[T];
int pai[T];
int qu[T], qv[T];
int lo[T], hi[T];
vector<int> palpite[T];

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    pai[find(x)] = find(y);
}

void initF() {
    for(int i = 1; i <= n; i++) pai[i] = i;
}

void reloadPalpite() {
    for(int i = 0; i <= q; i++) palpite[i].clear();
    for(int i = 1; i <= m; i++) {
        int mid = (lo[i] + hi[i])>>1;
        palpite[mid].pb(i);
    }
}

void check(int jo) {
    bool flag = true;
    for(int i = 1; i < jogo[jo].size(); i++) {
        int x = jogo[jo][i];
        int y = jogo[jo][i-1];
        flag &= (find(pai[x]) == find(pai[y]));
    }
    int mid = (lo[jo] + hi[jo])>>1;
    if(flag) hi[jo] = mid;
    else lo[jo] = mid+1; 
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> amigo[i];
        jogo[amigo[i]].pb(i);
    }
    for(int i = 1; i <= q; i++) 
        cin >> qu[i] >> qv[i];
    for(int i = 1; i <= m; i++) {
        lo[i] = 0, hi[i] = q;
    }
    for(int i = 0; i <= 20; i++) {
        initF();
        reloadPalpite();
        for(int j = 0; j <= q; j++) {
            if(j > 0) join(qu[j], qv[j]);
            for(int k = 0; k < palpite[j].size(); k++)
                check(palpite[j][k]);
        }
    }

    for(int i = 1; i <= m; i++) 
        cout << (lo[i] > q? -1 : lo[i]) << endl;

    return 0;
}

