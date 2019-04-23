#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
vector<int> track[T];
int qtd[T];
int sum[T];
int v[T];

ii seg[4*T];

void build(int node, int i, int j) {
    if(i == j) seg[node] = ii(sum[i],sum[i]);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);

        seg[node] = ii(seg[2*node].fi + seg[2*node+1].fi,
            max(seg[2*node].se, seg[2*node+1].se);

        seg[node].se = max(seg[node].fi, seg[node].se);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int cont = 0;
    int tc; cin >> tc;
    while(tc--) {
        int n, s;
        cin >> n >> s;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            qtd[v[i]]++;
            if(qtd[v[i]] <= s) sum[i]++;
            else if(qtd[v[i]] == s+1) sum[i] = -s, track[v[i]].pb(i);
            else sum[i] = 0, track[v[i]].pb(i);
        }

        for(int i = 1; i < n; i++) sum[i] += sum[i-1];
        build(1,1,n);


        cout << "Case #" << ++cont << ": " << ans << endl;
    }
    return 0;
}

