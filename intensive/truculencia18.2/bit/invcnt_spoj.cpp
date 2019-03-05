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

const int T = 1e7 + 10;
ll bit[T];

void update(int pos, int val) {
    for(; pos < T; pos += (pos & -pos)) bit[pos] += val;
}

ll query(int pos) {
    ll sum = 0;
    for(; pos; pos -= (pos & -pos)) sum += bit[pos];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    int tc, n, aux; cin >> tc;
    while(tc--) {
        cin >> n;
        ll ans = 0;
        memset(bit, 0, sizeof bit);
        for(int i = 1; i <= n; i++) {
            cin >> aux;
            ans += query(T-1) - query(aux);
            update(aux,1);
        }
        cout << ans << endl;
    }
    return 0;
}

