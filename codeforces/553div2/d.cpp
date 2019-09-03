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

vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
    ll n,a,b; cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) { 
        cin >> a >> b;
        ans += b*n - a;
        v.pb(a-b);
    }

    sort(v.begin(), v.end(), greater<int>());
    for(ll i = 0; i < n; i++)
        ans += v[i]*(i+1);

    cout << ans << endl;

    return 0;
}

