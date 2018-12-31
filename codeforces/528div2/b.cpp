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
    int n, k; cin >> n >> k;
    ll x;
    ll ans = LLONG_MAX;
    for(int rest = 1; rest <= k-1; rest++) {
        x = n/rest;
        x = x*k + rest;
        if((x/k) * (x%k) == n)
            ans = min(ans, x);
    }

    cout << ans << endl;

    return 0;
}

