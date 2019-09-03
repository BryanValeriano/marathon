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

ll n,s;  

int dig(ll x) {
    ll ans = 0;

    while(x) {
        ans += x%10;
        x /= 10;
    }

    return ans;
}

bool check(ll x) {
    return (x - dig(x)) >= s; 
}

int main() {
    ios::sync_with_stdio(false);
    ll ans = 0;
    cin >> n >> s;

    ll l = 0; 
    ll r = n; 

    while(r-l >= 1) {
        ll mid = (l+r) >> 1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }

    for(ll i = max(0LL, l-10); i <= l + 10; i++) 
        if(i - dig(i) >= s) { l = i-1; break; }

    cout << max(0LL,n-l) << endl;

    return 0;
}

