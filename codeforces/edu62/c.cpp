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

struct beu { 
    ll l, b; 
    bool operator < (const beu &x) {
        if(b != x.b) return b >= x.b;
        else return l >= x.l;
    }
};

ll ans;
multiset<ll> melhores;
vector<beu> beut;

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int u,v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        beut.pb({u,v});
    }
    sort(beut.begin(), beut.end());
    ll sum = 0;

    for(auto x : beut) {
        if(melhores.size() < k - 1) {
            melhores.insert(x.l);
            sum += x.l;
            ans = max(ans, sum * x.b);
        } else {
            ans = max(ans, (sum + x.l) * x.b);
            if(x.l > *melhores.begin() and k > 1) {
                sum -= *melhores.begin();
                sum += x.l;
                melhores.erase(melhores.begin());
                melhores.insert(x.l);
            }
        }
    }
    cout << setprecision(0) << fixed << ans << endl; 
    return 0;
}

