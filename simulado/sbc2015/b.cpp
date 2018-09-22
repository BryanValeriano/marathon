#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 3;
ll dp[T][2];
int row[T];
int n, c;

ll steve(int dia, int comprado) {

	if(dia == n) return 0;

	ll &r = dp[dia][comprado];
	
	ll R = 0;
	ll L = 0;
	if(r == -1) {
		if(comprado) 
			R = max(steve(dia + 1, 1), steve(dia + 1, 0) + row[dia]);
		else 
			L = max(steve(dia + 1, 0), steve(dia + 1, 1) - (c + row[dia]));

		return r = max(R, L);
	}
	return r;
}


int main() {
    ios::sync_with_stdio(false);
	cin >> n >> c;
	for(int i = 0; i < n; i++)
		cin >> row[i];
	memset(dp, -1, sizeof dp);

	cout << max(steve(0, 1) - (c + row[0]), steve(0,0)) << endl;

    return 0;
}

