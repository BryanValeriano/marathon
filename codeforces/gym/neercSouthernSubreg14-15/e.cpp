#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
 
typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int T = 2e5 + 4;
int n;
vector<ll> v;
vector<ii> ans;
bool vis[T];
 
ll metade(ll n) {
	ll x = n/2;
	return x;
}

bool isIn(int x) {
    return (x >= 0 and x < n);
}

bool fuck(int x, int y) {
    return ((v[x] + v[y] <= 0 and (v[x] > 0 or v[y] > 0)) or (v[x] > 0 and v[y] > 0));
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll tot = n;
	ll a, b;
	
	ll x = 0;
	ll y = metade(n);
 
	for(int i = 0; i < n; i++) {
		cin >>a >>b;
		v.pb(a-b);
		if(a-b > 0) x++;
	}
 
	for(int i = 0; i < n and x <= y; i++) {
        if(isIn(i-1) and !vis[i] and !vis[i-1] and !fuck(i,i-1)) {
            vis[i] = 1;
            vis[i-1] = 1;
            y = metade(--tot);
            ans.eb(i,i-1);
        }
        else if(isIn(i+1) and !vis[i] and !vis[i+1] and !fuck(i,i+1)) {
            vis[i] = 1;
            vis[i+1] = 1;
            y = metade(--tot);
            ans.eb(i,i+1);
        }
    }
	
	if(x <= y) {
		cout <<-1 <<endl;
		return 0;
	}
 
	cout <<ans.size() <<endl;
	for(ii at:ans) {
		cout <<at.fi+1 <<' ' <<at.se+1 <<endl;
	}
 
	return 0;
}
 
