#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 3e5+10;
const int N = 1e6+10;
const int LOGN = log2(N)+1;

ll n,w;
ll tot[T];
ll pontos[T];
ll lazyGrupo[N];
ll lazyInd[T];
ll bit[N];

void update(int pos, int val) {
    for(; pos < N; pos+=pos&(-pos)) bit[pos] += val;
}

ll query(int pos) {
    ll sum = 0;
    for(; pos; pos-=pos&(-pos)) sum += bit[pos];
    return sum;
}

int search(int x) {
    return query(N-1) - query(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w;

    for(int i = 1; i <= n; i++) {
        tot[i] = w;
        pontos[i] = 1;
        update(pontos[i],1);
    }

    for(int i = 0; i < w; i++) {
        int k; cin >> k;
        vii at;
        vector<int> ind;
        vector<int> rankVelho;

        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            tot[x] += (lazyGrupo[pontos[x]] + lazyInd[x]);
            at.eb(pontos[x], w-i);
            rankVelho.pb(search(pontos[x]));
            ind.eb(x);
        }

        for(ii x : at) lazyGrupo[x.fi] += x.se;

        for(int x : ind) {
            update(pontos[x],-1);
            pontos[x]++;
            update(pontos[x],1);
            lazyInd[x] = -lazyGrupo[pontos[x]];
        }

        for(int j = 0; j < ind.size(); j++) {
            int x = ind[j];
            ll rankNovo = search(pontos[x]);
            tot[x] -= (rankVelho[j] - rankNovo)*(ll)(w-i);
            }

    }

    for(int i = 1; i <= n; i++) {
        tot[i] += (lazyGrupo[pontos[i]] + lazyInd[i]);
        cout << fixed << setw(6) << ((double)tot[i]/(double)w) << endl;
    }

    return 0;
}

