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
    ll n,m,a,b;
    cin >> n >> m >> a >> b;

    ll x = a/m;
    if(a%m) x++;
    ll y = b/m;
    if(b%m) y++;

    if(x == y or m == 1) { cout << 1 << endl; return 0; }
    int ans = 3 - (a%m == 1 or a == 1) - (b%m == 0 or b == n);
    if(x+1 == y) ans = min(ans,2);
    cout << ans << endl;
    return 0;
}

