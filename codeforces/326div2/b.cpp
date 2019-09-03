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
    ll x; cin >> x;
    ll ans = 1;

    for(ll i = 2; i*i <= x; i++) {
        if(x % i == 0) {
            ans *= i;
            while(x % i == 0) x /= i;
        }
    }

    ans *= x;

    cout << ans << endl;

    return 0;
}

