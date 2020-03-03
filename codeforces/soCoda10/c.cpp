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
const int T = 1e5 + 5;
ll v[T];
ll n;

ll check(ll mid) {
    ll a = mid/n;
    ll b = mid%n;
    a = v[a], b = v[b];

    ll ans = 0;

    int l = 0;
    int r = 0;

    while(r < n and v[r] <= b) r++;
    while(l < n and v[l] < a) l++, ans += n;
    while(l < n and v[l] <= a) l++, ans += r;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);

    ll l = 0;
    ll r = n*n-1;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid) >= k) ans = mid, r = mid-1;
        else l = mid+1;
    }


    l = ans/n;
    r = ans%n;

    cout << v[l] << " " << v[r] << endl;

    return 0;
}

