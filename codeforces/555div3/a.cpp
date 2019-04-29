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

set<ll> ans;

void solve(ll x) {
    if(ans.count(x)) return;
    while(x % 10 == 0) x /= 10;
    ans.insert(x);
    solve(x+1);
    ans.insert(x);
}
    


int main() {
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    solve(n+1);
    ans.insert(n);
    cout << ans.size() << endl;
    return 0;
}

