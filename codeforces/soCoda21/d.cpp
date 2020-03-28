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
const int T = 100;

ll qtd[T+2];
map<ll,int> lg;
ll n,m;

bool tryBefore(int x) {
    for(int i = 0; i < x; i++) {
        qtd[i+1] += qtd[i]/2;
        qtd[i] = 0;
    }
    return qtd[x];
}

int tryAfter(int x) {
    for(int i = x+1; i < T; i++) {
        if(qtd[i]) {
            for(int j = i; j > x; j--) {
                qtd[j-1] += 2;
                qtd[j]--;
            }
            return i-x;
        }
    }
    return -1;
}

ll solve() {
    ll ans = 0;
    for(ll i = 1; i <= n; i <<= 1) {
        if(n&i) {
            if(!tryBefore(lg[i])) {
                ll x = tryAfter(lg[i]);
                if(x == -1) return -1;
                qtd[lg[i]]--;
                ans += x;
            } else qtd[lg[i]]--;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(ll i = 1, j = 0; i <= 2e18; i <<= 1, j++) lg[i] = j;

    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        memset(qtd,0,sizeof qtd);
        for(int i = 0; i < m; i++) {
            ll x; cin >> x;
            qtd[lg[x]]++;
        }
        cout << solve() << endl;
    }

    return 0;
}

