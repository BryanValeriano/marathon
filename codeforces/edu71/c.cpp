#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll INF = 2e8;
const double PI = acos(-1.0);

const int T = 2e5 + 4;
ll dp[T][2];
int vis[T][2];
int vez;
string s;
ll n,a,b;

ll solve(int at, int h) {
	if(at == n+1) return (h == 1? 0 : INF);
	if(vis[at][h] == vez) return dp[at][h];

	if(h == 1) {
		if(s[at+1] >= '1') dp[at][h] = solve(at+1,h+1) + 2ll*a+2ll*b;
		else dp[at][h] = min(solve(at+1,h+1) + 2ll*a+2ll*b, solve(at+1,h) + a+b);
	} else {
		if(s[at+1] >= '1') dp[at][h] = solve(at+1,h) + a+2ll*b;
		else dp[at][h] = min(solve(at+1,h) + a+2ll*b, solve(at+1,h-1) + 2ll*a+b);
	}

	//dp[at][h] = min({solve(at+1,h) + a+b*h, solve(at+1,h+1) + 2*a+(b*(h+1)) , solve(at+1,h-1) + 2*a+(b*(h-1))});
	vis[at][h] = vez;
	return dp[at][h];
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;

	while(tc--) {
		vez++;
		cin >> n >> a >> b >> s;
		s = '0' + s;
		s += '0';
		for(int i = 1; i <= n; i++) if(s[i] == '0' and s[i-1] == '1') s[i] = '2';
		cout << solve(1,1)+b << endl;

	}

    return 0;
}
