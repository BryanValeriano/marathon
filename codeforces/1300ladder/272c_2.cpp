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
const int T = 1e5 + 5;
ll v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int q; cin >> q;
    ll last = 1;
    for(int i = 1; i <= q; i++) {
        int w,h; cin >> w >> h;
        cout << max(last, v[w]) << endl;
        last = max(last, v[w]) + h;
    }
    return 0;
}

