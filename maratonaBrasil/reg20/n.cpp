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

const int N = 4e7;
const int M = 3e6;
const int K = 1e3+2;
ll prime[N], u[N];
int sz;

vector<ii> g[K];
ll v[K], ans[K];

void pre() {
    for(ll i=2;i< N;++i) {
        if(!u[i]) u[i] = prime[sz++] = i;
        for(ll j=0;i*prime[j] < N ; ++j){
            u[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    pre();

    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < k; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        g[a].eb(b,w);
    }


    int pos = 0;
    int last = 0;
    for(int i = 1; i <= m; i++) {
        ii at = g[i][0];
        while(pos < sz and (v[at.fi] % (ll)prime[pos])) pos++;

        if(pos == sz) break;
        last = i;
        ans[i] = prime[pos];

        for(int j = 0; j < g[i].size(); j++) {
            while(g[i][j].se) {
                g[i][j].se--;
                v[g[i][j].fi] /= ans[i];
            }
        }
        cout << ans[i] << " ";
    }

    for(int i = last+1; i <= m; i++) {
        ii at = g[i][0];
        ans[i] = v[at.fi];
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

