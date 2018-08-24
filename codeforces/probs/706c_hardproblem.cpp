#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF =  1LL<<60;
const int TAM = 1e5 + 3;
int row[TAM];
ll dp[TAM][2];
string pals[TAM];
string inv[TAM];
	
int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> row[i];
	for(int i = 1; i <= n; i++) {
		cin >> pals[i];
		inv[i] = pals[i];
		reverse(inv[i].begin(), inv[i].end());
		dp[i][0] = dp[i][1] = INF;
	}

	dp[1][0] = 0;
	dp[1][1] = row[1];
	for(int i = 2; i <= n; i++) {
		if(pals[i] >= pals[i-1]) 
			dp[i][0] = dp[i-1][0];
		if(pals[i] >= inv[i-1])
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		if(inv[i] >= pals[i-1])
			dp[i][1] = dp[i-1][0] + row[i];
		if(inv[i] >= inv[i-1])
			dp[i][1] = min(dp[i][1], dp[i-1][1]+row[i]); 
	}
	
	ll resp = min(dp[n][0], dp[n][1]);
	cout << (resp==INF ? -1 : resp) << endl; 
    return 0;
}

