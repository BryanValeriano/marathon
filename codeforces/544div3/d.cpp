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
ll a[T];
ll b[T];
int n;

int count(ll d, int tipo) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(tipo == 0 and (a[i] * d) + b[i] == 0) ans++;
        else if(tipo == 1 and (b[i] * d) + a[i] == 0) ans++;
    }
    cout << d << ": " << ans << endl;
    return ans;
}

int ternary(int l, int r, int tipo) {
    while(r - l >= 0) {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = count(m1,tipo);
        double f2 = count(m2,tipo);
        if(f1 < f2) l = m1 + 1;
        else r = m2 - 1;
    }
    return count(l,tipo);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans1 = ternary(-1e9, 1e9, 0);
    ll ans2 = ternary(-1e9, 1e9, 1);
    cout << max(ans1, ans2) << endl;
    return 0;
}

