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
int a,b,c;

int digit(ll x) {
    int ans = 0;
    while(x > 0) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    vector<ll>resp;
    for(int i = 1; i <= 90; i++) {
        ll ans = b*(powl(i,a)) + c;
        if(ans < 0 or ans > 1e9) continue;
        if(digit(ans) == i) resp.pb(ans);
    }
    cout << resp.size() << endl;
    for(auto x : resp)
        cout << x << " ";
    cout << endl;
    return 0;
}

