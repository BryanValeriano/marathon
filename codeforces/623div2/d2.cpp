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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 100;
const ll N = 1e10 + 100;
ll v[T], p[T];
vector<ii> qtd;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        qtd.eb(v[i],p[i]);
    }

    ll ans = 0;
    ll tot = 0;

    sort(qtd.begin(), qtd.end());
    priority_queue<int, vector<int> > pq;
    ii at;
    ll i = 1;
    int p = 0;

    while(i < N and (p < qtd.size() or pq.size())) {
        at = (p < qtd.size()? qtd[p] : mk(-1ll,-1ll));;

        while(at.fi == i) {
            tot += (ll)at.se;
            pq.emplace(at.se);
            p++;
            at = (p < qtd.size()? qtd[p] : mk(-1ll,-1ll));;
        }

        if(pq.size()) {
            ll top = pq.top();
            pq.pop();
            tot -= top;
            i++;
        } else {
            i = (at.fi == -1? N : at.fi);
        }

        ans += tot;
    }

    cout << ans << endl;

    return 0;
}
