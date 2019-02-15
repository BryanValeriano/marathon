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
const int T = 1e5 + 10;
vector<int> v(T);
ll n,k,a,b;

ll brute(ll l, ll r) {
    ll low = lower_bound(v.begin(), v.end(), l) - v.begin();
    ll up = upper_bound(v.begin(), v.end(), r) - v.begin();
    
    if((up-low) == 0) return a;
    ll ans = (r-l+1) * b * (up-low); 
    if(l == r) return ans;

    int mid = (l+r) >> 1;
    ans = min(ans, brute(l, mid) + brute(mid+1,r));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> a >> b;
    for(int i = 0; i < k; i++) cin >> v[i];
    sort(v.begin(),v.end());

    cout << brute(1,pow(2,n)) << endl;

    return 0;
}

