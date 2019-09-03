#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 102;
const int N = 1e4 + 2;

int dp[T][N];
int n, t;
int v[T];

int solve(int at, int comendo) {
	if(comendo > t) return -INF;
	if(at == n) return 0;
	if(dp[at][comendo] != -1) return dp[at][comendo];

	dp[at][comendo] = max(solve(at+1, comendo), solve(at+1,comendo + v[at])+ 1);
	return dp[at][comendo];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> n >> t;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] *= n-i;
	}
	cout << solve(0,0) << endl;
    return 0;
}

