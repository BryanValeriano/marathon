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
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(),v.end());
    ll ans = v[0];

    if(v[2]-v[1] <= v[0]) {

        v[0] -= v[2]-v[1];
        v[2] = v[1];

        v[2] -= v[0]/2;
        v[1] -= v[0]/2 + (v[0]&1);
    } else {
        v[2] -= v[0];
    }

    ll maxi = max(v[2],v[1]);
    for(int i = 3; i < n; i++) maxi = max(maxi,v[i]-ans);
    ans += maxi;

    cout << ans << endl;


    return 0;
}

