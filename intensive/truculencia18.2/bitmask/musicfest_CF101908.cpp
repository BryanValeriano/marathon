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
const ll INF = 0x3f3f3f3f3f3f3f;
const int N = 1030;
int gol;
int prox[N];
ll dp[N][N];

struct node { 
    int ini,fim,stage,pts;

    bool operator < (const node &b) const {
        if(ini != b.fim) return ini <= b.fim;
        return false;
    }
    
};
vector<node> shows;

bool cmp(const node &a, const node &b) {
    if(a.ini != b.ini) return a.ini < b.ini;
    return false;
}

ll solve(int atual, ll mask) {
    if(atual >= shows.size() and mask != gol) return -INF;
    if(atual >= shows.size() and mask == gol) return 0;
    
    ll &r = dp[atual][mask];
    if(r != -1) return r;
    ll ans = -INF;

    ans = max(ans, solve(prox[atual], mask | (1 << shows[atual].stage)) + shows[atual].pts);
    ans = max(ans, solve(atual + 1, mask));

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);

    int stages; cin >> stages;
    gol = pow(2,stages)-1;

    int ini,fim,pts;
    for(int i = 0; i < stages; i++) {
        int s; cin >> s;
        for(int j = 0; j < s; j++) {
            cin >> ini >> fim >> pts;
            shows.pb({ini,fim,i,pts});
        }
    }

    sort(shows.begin(), shows.end(), cmp);

    for(int i = 0; i < shows.size(); i++) 
        prox[i] = lower_bound(shows.begin(), shows.end(), shows[i]) - shows.begin();

    memset(dp, -1, sizeof dp);
    ll ans = solve(0,0);
    cout << (ans <= -1? -1 : ans) << endl;

    return 0;
}

