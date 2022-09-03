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
const int T = 1<<18;
ll dp[T];
ii seg[2*T];
int v[T];
int n;

void build() {
    for(int i = 0; i < n; i++) seg[i+n] = mk(v[i],i);
    for(int i = n-1; i >= 0; i--) seg[i] = max(seg[2*i],seg[2*i+1]);
}

int query(int l, int r) {
    ii ans = mk(0,0);
    for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) ans = max(ans,seg[l++]);
        if(r & 1) ans = max(ans,seg[--r]);
    }
    return ans.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> v[i], v[i]--;
    v[n-1] = INF;
    build();

    ll ans = 0;
    for(int i = n-2; i >= 0; i--) {
        int m = query(i+1,v[i]);
        dp[i] = dp[m] + (n-i-1) - (v[i]-m);
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}

