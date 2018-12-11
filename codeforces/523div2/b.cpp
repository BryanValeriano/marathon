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
const int T = 1e5+10;
ll v[T];
int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    ll sum = 0;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v+1, v+n+1);
    set<ll>ind;
    ll cont = 1;
    for(ll i = 1; i < n; i++) {  
        ind.insert(min(cont,v[i]));
        if(v[i] >= cont) cont++;
    }
    ll h = v[n];
    h -= ind.size();
    h = max(1LL, h);
    cout << sum - ((n-1) + h) << endl;
    return 0;
}

