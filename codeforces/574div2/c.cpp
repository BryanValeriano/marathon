    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
    #define eb emplace_back
    #define mk make_pair
    #define fi first
    #define se second
    #define cc(x)	cout << #x << " = " << x << endl
    #define ok		cout << "ok" << endl
    #define endl '\n'
     
    typedef long long ll;
    typedef pair<int,int> ii;
    const int INF = 0x3f3f3f3f;
    const double PI = acos(-1.0);
     
    const int T = 2e5 + 5;
    ll a[T];
    ll b[T];
    ll v[T];
    ll dp[T][2];
    ll n;
     
    ll solve(int at, int r) {
    	if(at >= 2*n) return 0;
    	if(dp[at][r] != -1) return dp[at][r];
     
    	if((at&1) != r) return dp[at][r] = solve(at+1, r);
    	
    	return dp[at][r] = max(solve(at+1, r), solve(at+1+ (!r), !r) + v[at]);
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
    	memset(dp, -1, sizeof dp);
    	cin >> n;
    	for(int i = 0; i < n; i++) cin >> a[i];
    	for(int i = 0; i < n; i++) cin >> b[i];
     
    	int l = 0;
    	int r = 0;
     
    	for(int i = 0; i < 2*n; i++) {
    		if(i&1) v[i] = a[r++];
    		else v[i] = b[l++];
    	}
     
    	cout << max(solve(0,1), solve(0,0)) << endl;
        return 0;
    }
     
