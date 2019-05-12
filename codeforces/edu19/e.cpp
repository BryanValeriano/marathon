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

const int T = 1e5 + 10;
ll v[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int q; cin >> q;
    
    ll p,k;
    while(q--) {
        cin >> p >> k;
        int ans = 0;
        while(p <= n) p += v[p] + k, ans++;
        cout << ans << '\n';
    }

    return 0;
}

