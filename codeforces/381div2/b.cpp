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
const int T = 105;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll ans = 0;
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    while(m--) {
        int l,r; cin >> l >> r;
        if(v[r]-v[l-1] > 0) ans += v[r] - v[l-1];
    }
    cout << ans << endl;
    return 0;
}

