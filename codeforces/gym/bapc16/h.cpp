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

bool erase(vector<ll> &v, int base) {
    bool dp[base+1];
    ll choose[base+1];
    memset(dp,0,sizeof dp);
    memset(choose,0,sizeof choose);

    for(ll x : v) {
        for(ll i = base-1; i >= x*2ll; i--) {
            if(i%x) continue;
            if(dp[i/x]) {
                dp[i] = 1;
                choose[i] = x;
            }
        }
        if(!dp[x]) {
            dp[x] = 1;
            choose[x] = x;
        }
    }

    int ans = 0;
    for(int i = base-1; i >= 0; i--) {
        if(dp[i] and choose[i] != i) {
            ans = i;
            break;
        }
    }

    if(!ans) return 0;

    vector<ll> del;
    ll novo = ans;

    while(ans > 1) {
        del.pb(choose[ans]);
        ans /= choose[ans];
    }

    for(ll x : del) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == x) {
                v.erase(v.begin()+i);
                break;
            }
        }
    }

    v.pb(novo);
    return 1;
}

void solve(vector<ll> &v, int base) {
    while(erase(v,base)) continue;
}

vector<ll> fats(ll x) {
    vector<ll> fs;
    for (ll i = 2;i * i <= x;i++) {
        while (x % i == 0) {
            fs.push_back(i);
            x /= i;
        }
    }
    if (x > 1) fs.push_back(x);
    sort(fs.rbegin(), fs.rend());
    return fs;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll b, n;
    cin >> b >> n;
    vector<ll> fs = fats(n);
    ll ans = 0, x = 1, y = 1;

    for(ll x : fs) {
        cerr << x << " ";
        if(x >= b) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cerr << endl;

    solve(fs, b);
    sort(fs.rbegin(), fs.rend());
    for(ll x : fs) cerr << x << " ";
    cerr << endl;

    for (auto& f : fs) {
        ans += f * y;
        y *= b;
    }

    if (ans < 0) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}

