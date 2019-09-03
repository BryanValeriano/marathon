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

int main() {
    ios::sync_with_stdio(false);
    ll tc;
    ll n,k;
    cin >> tc;

    while(tc--) {
        cin >> n >> k;
        ll ans = 0;
        while(n) {
            if(n%k == 0) {
                n /= k, ans++;
            } else {
                ll x = n - (n/k)*k;
                ans += x;
                n -= x;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

