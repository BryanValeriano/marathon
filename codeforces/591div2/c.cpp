#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;
ll v[T];
ll p[T];
int n;
ll x,a,y,b,k;

bool check(int d) {
    priority_queue<ll, vector<ll>, greater<ll> > tk;
    priority_queue<ll, vector<ll>, greater<ll> > bon;

    for(int i = 1; i <= d; i++) {
        tk.emplace(v[i]);
        bon.emplace(p[i]);
    }

    ll ans = 0;

    while(tk.size()) {
        ll z = tk.top();
        tk.pop();
        ll h = bon.top();
        bon.pop();
        ans += h*z;
    }
    
    return (ans >= k);

}
 
int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> v[i], v[i] /= 100ll;
        cin >> x >> a >> y >> b;
        cin >> k;

        sort(v+1, v+n+1, greater<ll>());

        for(int i = 1; i <= n; i++) {
            p[i] = 0;
            if(i % a == 0) p[i] += x;
            if(i % b == 0) p[i] += y;
        }

        int l = 1;
        int r = n;
        int ans = INF;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        cout << (ans == INF? -1 : ans) << endl;
    }
    return 0;
}

