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
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 301;
const int LOGN = log2(T);
int g[T][T];
int bit[2][T];
int n,m,k,c,tot;

void update(int id, int val, int pos) {
    for(;pos < T; pos += pos&(-pos)) bit[id][pos] += val;
}

int search(int x) {
    int sum = 0;
    int below = 0;
    int pos = 0;
    for(int i = LOGN; i >= 0; i--) {
        if(pos + (1<<i) < T and sum + bit[1][pos+(1<<i)] < x) {
            sum += bit[1][pos+(1<<i)];
            below += bit[0][pos+(1<<i)];
            pos += (1 << i);
        }
    }
    if(pos+1 > T) return below;
    return below+(pos+1)*(x-sum-1);
}

bool can(int l, int u, int r, int d) {
    return (search(max(0,tot-k+1)) <= c);
}

void change(int x, int op, int l, int r) {
    int line = g[x][r]-(l? g[x][l-1] : 0);
    tot += (line > 0)*op;
    if(line) {
        update(1,1*op,line);
        update(0,line*op,line);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> c;
    while(n or m or k or c) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> g[i][j];
                g[i][j] = !g[i][j];
                if(j) g[i][j] += g[i][j-1];
            }
        }
        int ans = 0;
        for(int l = 0; l < m; l++) {
            for(int r = l; r < m; r++) {
                int d = -1;
                int u = 0;
                while(u < n) {
                    if(u > d) change(u,1,l,r);
                    d = max(d,u);
                    while(d < n and can(l,u,r,d)) {
                        ans = max(ans, (r-l+1)*(d-u+1));
                        d++;
                        if(d < n) change(d,1,l,r);
                    }
                    change(u,-1,l,r);
                    u++;
                }
            }
        }
        cout << ans << endl;
        cin  >> n >> m >> k >> c;
    }
    return 0;
}

