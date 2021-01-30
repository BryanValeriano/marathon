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
const int T = 202;
const int N = 2e3+2;
int mat[T][T];
int aux[N];
int n,m;

int solve(int a, int b, int c, int d) {
    int qtd = 0;
    for(int i = a-1; i < b; i++)
        for(int j = c-1; j < d; j++) {
            aux[mat[i][j]]++;
            qtd++;
        }

    int gol = (qtd>>1) + 1;
    for(int i = 0; i < N; i++) {
        gol -= aux[i];
        if(gol <= 0) return i;
    }

    return 0;
}

void zero(int a, int b, int c, int d) {
    for(int i = a-1; i < b; i++)
        for(int j = c-1; j < d; j++)
            aux[mat[i][j]]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("important.in","r",stdin);
    int t; cin >> t;
    int cont = 0;
    while(t--) {
        cout << "Case " << ++cont << ":\n";
        int q; cin >> n >> m >> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];
        while(q--) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            cout << solve(a,c,b,d) << endl;
            zero(a,c,b,d);
        }
    }
    return 0;
}

