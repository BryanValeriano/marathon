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

const int T = 1e3 + 5;
const ll MOD = 1e9 + 7;
int mat[T][T];
int prob[T][T];
int n,m;

void buildR(int pos, int qtd) {
    if(qtd == 0) prob[pos][0]++;
    for(int i = 0; i < qtd; i++)
        mat[pos][i]++;
    prob[pos][qtd]++;
}

void buildC(int pos, int qtd) {
    if(qtd == 0) prob[0][pos]++;
    for(int i = 0; i < qtd; i++)
        mat[i][pos]++;
    prob[qtd][pos]++;
}

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        buildR(i,x);
    }
    for(int i = 0; i < m; i++) {
        cin >> x;
        buildC(i,x);
    }

    int z = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(mat[i][j] and prob[i][j]) {
                cout << 0 << endl;
                return 0;
            }
            if(!mat[i][j] and !prob[i][j]) z++;
        }

    cout << ele(2,z) << endl;
    return 0;
}

