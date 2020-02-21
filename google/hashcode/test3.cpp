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

const int T = 1e6 + 5;
bool vis[T];
ll score[T];
int b,l,d;

struct lib {
    ll n,t,m,id,sc;
    vector<int> ids;

    lib(int n, int t, int m, int id, ll sc) :
        n(n), t(t), m(m), id(id), sc(sc) {}

    bool operator < (const lib &b) const {
        if(t*t - sc != b.t*b.t - b.sc) {
            return t*t - sc < b.t*b.t - b.sc;
        }
        return id < b.id;
    }
};

vector<lib> libs;
vector<lib> ans;


void read() {
    cin >> b >> l >> d;
    for(int i = 0; i < b; i++) cin >> score[i];

    for(int i = 0; i < l; i++) {
        int n,t,m;
        cin >> n >> t >> m;
        lib tmp = lib(n,t,m,i,0);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            tmp.ids.pb(x);
            tmp.sc += (ll)score[x];
        }
        libs.pb(tmp);
    } 

    sort(libs.begin(), libs.end());
}

void solve() {
    int used = 0;

    for(int i = 0; i < l; i++) {
        if(used + libs[i].t > d) break;
        lib tmp(0,0,0,libs[i].id,0);
        used += libs[i].t;
        int lim = (d-used) * libs[i].m;

        for(auto livro : libs[i].ids) {
            if(tmp.n > lim) break;
            if(vis[livro]) continue;
            vis[livro] = 1;
            tmp.n++;
            tmp.ids.pb(livro);
        }

        if(tmp.n) ans.pb(tmp);
    }
} 

void output() {
    cout << ans.size() << endl;
    for(auto livr : ans) {
        cout << livr.id << " " << livr.n << endl;
        for(auto livro : livr.ids) cout << livro << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    solve();
    output();
    return 0;
}

