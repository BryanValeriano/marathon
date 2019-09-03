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

const int T = 2e5 + 10;
int pos[T];
int bit[T];

void update(int x, int val) {
    for(int i = x; i < T; i += i&-i) bit[i] += val;
}

int query(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= i&-i) ans += bit[i];
    return ans;
}

void solve() {
    memset(bit, 0, sizeof bit);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        pos[i] = n - i + 1;
        update(pos[i],1);
    }
    
    int q; cin >> q;
    int top = n;

    while(q--) {
        int at; cin >> at;
        cout << n - query(pos[at]) << " ";
        update(pos[at], -1);
        pos[at] = ++top;
        update(pos[at], 1);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}

