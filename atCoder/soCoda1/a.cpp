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
const int T = 1e5 + 2;
int v[T];
int l[T];
int r[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        l[i] = v[i];
        if(i > 1) l[i] = __gcd(l[i],l[i-1]);
    }

    for(int i = n; i >= 1; i--) {
        r[i] = v[i];
        if(i < n) r[i] = __gcd(r[i],r[i+1]);
    }

    for(int i = 1; i <= n; i++)
        ans = max(ans, __gcd(i-1 >= 1? l[i-1] : r[i+1], i+1 <= n? r[i+1] : l[i-1]));

    cout << ans << endl;

    return 0;
}

