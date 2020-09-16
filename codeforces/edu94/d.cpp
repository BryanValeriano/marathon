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
const int T = 3e3+4;
const int N = 5;
ll choose[T][N];
vector<int> g[T];

void pre() {
    for(int i = 0; i < T; i++) choose[i][0] = 1;
    for(int i = 0; i < N; i++) choose[i][i] = 1;

    for(int i = 1; i < T; i++)
        for(int j = 1; j < N; j++)
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
}

vector<int> build(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<int> preB(m,0);
    int l = 0, r = 0;
    while(r < m) {
        while(l < n and a[l] <= b[r]) l++;
        preB[r] = l+(r?preB[r-1]:0);
        r++;
    }
    return preB;
}

ll inter(vector<int> &preB, int r, int l) {
    ll cut = preB[l];
    ll shit = (preB[l]-(l?preB[l-1]:0))*(r-l);
    return preB[r]-cut-shit;
}

ll calc(vector<int> &a, vector<int> &b) {
    int j = 0;
    int n = a.size();
    int m = b.size();
    if(!n or !m) return 0;

    //b vai ser j,l
    vector<int> preB = build(a,b);
    ll ans = 0;

    while(j < m) {
        ll is = preB[j]-(j?preB[j-1]:0);
        ll ks = inter(preB,m-1,j);
        ans += is*ks;
        j++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    pre();
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <=  n; i++) g[i].clear();
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            g[x].pb(i);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += choose[g[i].size()][4];
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
//                cout << i << " " << j << " = " << calc(g[i],g[j]) << endl;
                ans += calc(g[i],g[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

