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
const int N = 3;
int sz[N];
vector<int> v[N];

int getAf(int a, int pos) {
    int low = lower_bound(v[pos].begin(),v[pos].end(),a) - v[pos].begin();
    return (low < v[pos].size()? v[pos][low] : 0);
}

int getBef(int a, int pos) {
    int low = lower_bound(v[pos].begin(),v[pos].end(),a) - v[pos].begin();
    low--;
    return (low >= 0? v[pos][low] : 0);
}

ll dist(ll x, ll y, ll z) {
    return((x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z));
}

ll solve(ll z, vector<ll> &x, vector<ll> &y) {
    ll ans = LLONG_MAX;

    for(ll xx : x)
        if(xx)
            for(ll yy : y)
                if(yy)
                    ans = min(ans,dist(xx,yy,z));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < N; i++) cin >> sz[i];

        for(int i = 0; i < N; i++) {
            v[i].clear();
            for(int j = 0; j < sz[i]; j++) {
                int x; cin >> x;
                v[i].pb(x);
            }
            sort(v[i].begin(),v[i].end());
        }

        ll ans = LLONG_MAX;

        for(int i = 0; i < sz[2]; i++) {
            vector<ll> tmp[2];
            for(int j = 0; j < 2; j++) {
                tmp[j].pb(getAf(v[2][i],j));
                tmp[j].pb(getBef(v[2][i],j));
            }

            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    if(tmp[j][k]) {
                        tmp[!j].pb(getAf((tmp[j][k]+v[2][i])>>1,!j));
                        tmp[!j].pb(getBef((tmp[j][k]+v[2][i])>>1,!j));
                    }
                }
            }

            ans = min(ans, solve(v[2][i],tmp[0],tmp[1]));
        }

        cout << ans << endl;
    }
    return 0;
}

