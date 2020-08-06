#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 2e5 + 2;
ll l[T];
ll r[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(i-x >= 1) l[i-x]++;
        if(i+x <= n) r[i+x]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += l[i]*r[i];
    cout << ans << endl;
    return 0;
}

