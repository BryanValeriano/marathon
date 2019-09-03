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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int T = 3e3 + 10;
int part[T];
int n,m;
vii pessoas;
vii partidos;
int alvo;
ll dp[T][T];

ll tent(int atual, int falta) {
    if(falta <= 0) return 0;
    if(atual == n) return INF;
    
    ll &r = dp[atual][falta];
    if(r != -1) return r;

    ll ans = tent(atual + 1, falta - (pessoas[atual].fi == alvo? 2 : 1)) + pessoas[atual].se; 
    ans = min(ans, tent(atual + 1, falta));

    return r = ans;
}

bool cmp(const ii &a, const ii &b) {
    if(a.se != b.se) return a.se > b.se;
    return false;
}

bool cmp2(const ii &a, const ii &b) {
    if(a.se != b.se) return a.se < b.se;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a != 1) pessoas.eb(a,b);
        part[a]++;
    }

    for(int i = 1; i <= m; i++) 
        partidos.eb(i, part[i]);
    
    sort(partidos.begin(), partidos.end(), cmp);

    if(partidos[0].fi == 1 and partidos[0].se > partidos[1].se) { cout << 0 << endl; return 0; }

    alvo = partidos[0].fi;
    ll need = partidos[0].se + 1 - part[1];

    sort(pessoas.begin(), pessoas.end(), cmp2);

    if(partidos[0].se == partidos[1].se) alvo = 1;

    memset(dp, -1, sizeof dp);
    n = pessoas.size();

    cout << tent(0, need) << endl;

    return 0;
}

