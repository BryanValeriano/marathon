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
const int N = 1000 + 10;
const int M = 1024 + 10;

struct show {
    int stage;
    int ini;
    int fim;
    int qtd;
    
    show (int stage, int ini, int fim, int qtd) :
        stage(stage), ini(ini), fim(fim), qtd(qtd) {}
};

int stages;
int gol;
vector<show>shows;

bool cmp(const show &a, const show &b) {
    return a.ini < b.ini;
}

ll memo[N][M];
ll dp(int iter, int lastshow, int palcos) {
    if(iter == shows.size()) {
        if(palcos == gol) {
            return 0;
        } else return -INF;
    }
    ll &r = memo[lastshow][palcos];
    if(r != -1) return r;

    ll ans = -INF;
    if(shows[iter].ini >= lastshow) 
        ans = max(ans, dp(iter + 1, shows[iter].fim, palcos | shows[iter].stage) + shows[iter].qtd);
    ans = max(ans, dp(iter + 1, lastshow, palcos));
    
    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> stages;
    vector<int>ve;
    for(int i = 1; i <= stages; i++) {
        int qtd; cin >> qtd;
        for(int j = 0; j < qtd; j++) {
            int ini, fim, qtd;
            cin >> ini >> fim >> qtd;
            show tmp = show(0, ini, fim, qtd);
            tmp.stage |= 1<<i-1;
            gol |= 1<<i-1;
            shows.pb(tmp);
            ve.pb(fim);
            ve.pb(ini);
        }
    }
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    map<int,int>id;
    for(int i = 1; i < ve.size(); i++)
        id[ve[i]] = i;
    for(int i = 0; i < shows.size(); i++) {
        shows[i].ini = id[shows[i].ini];
        shows[i].fim = id[shows[i].fim];
    }
    sort(shows.begin(), shows.end(), cmp);
    memset(memo, -1, sizeof memo);
    ll ans = dp(0,0,0);
    cout << (ans < 0? -1 : ans) << endl;
    return 0;
}

