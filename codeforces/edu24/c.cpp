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

struct node {
    int cima,baixo,esq,dir;
    int up = 0,down = 0,le = 0,ri = 0;

    node(int a, int b, int c, int d) :
        cima(a), baixo(b), esq(c), dir(d) {}
};

const int T = 1e5 + 5;

int e[T];
int d[T];
int c[T];
int b[T];

vector<int> ee[T];
vector<int> dd[T];
vector<int> cc[T];
vector<int> bb[T];

int n, n1, n2;
int cnte, cntd, cntc, cntb;
vector<node> v;

void swep_line() {
    for(int i = 1; i <= n1; i++) {
        for(int j = 0; j < dd[i].size(); j++)
            v[dd[i][j]].le = e[i-1] - (v[dd[i][j]].esq <= (i-1));
        e[i] += e[i-1];
    }
    for(int i = n1; i >= 0; i--) {
        for(int j = 0; j < ee[i].size(); j++)
            v[ee[i][j]].ri = d[i+1] - (v[ee[i][j]].dir >= (i+1));
        d[i] += d[i+1];
    }
    for(int i = 1; i <= n2; i++) {
        for(int j = 0; j < bb[i].size(); j++)
            v[bb[i][j]].up = c[i-1] - (v[bb[i][j]].cima <= (i-1));
        c[i] += c[i-1];
    }
    for(int i = n2; i >= 0; i--) {
        for(int j = 0; j < cc[i].size(); j++)
            v[cc[i][j]].down = b[i+1] - (v[cc[i][j]].baixo >= (i+1));
        b[i] += b[i+1];
    }
}

int solve() {
    swep_line();
    for(int i = 0; i < n; i++) { 
        if(v[i].le == cnte and v[i].ri == cntd and v[i].up == cntc and v[i].down == cntb)
            return i+1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> n1 >> n2;
    int w,x,y,z;

    for(int i = 0; i < n; i++) {
        cin >> w >> x >> y >> z;
        int cima = min(x,z);
        int baixo = max(x,z);
        int esq = min(w,y);
        int dir = max(w,y);
        v.pb(node(cima,baixo,esq,dir));
        c[cima]++; 
        b[baixo]++;
        e[esq]++;
        d[dir]++;

        cc[cima].pb(i); 
        bb[baixo].pb(i);
        ee[esq].pb(i);
        dd[dir].pb(i);

    }
    
    cin >> cnte >> cntd >> cntc >> cntb;

    cout << solve() << endl;

    return 0;
}

