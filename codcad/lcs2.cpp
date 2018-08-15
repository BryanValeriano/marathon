#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e3+3;

int a[TAM];
int dp[TAM][TAM];

int lcs(int i, int last) {
	if(i < 0) return 0;
	if(a[i] < a[last]) return 1 + lcs(i, j - 1);
	if(dp[i][last] != -1) return dp[i][j];
	
	int R = lcs(i - 1, last);
	int L = lcs(i, j - last);

	return dp[i][j] = max(R,L);
}

int main() {
    ios::sync_with_stdio(false);
	int tam1;
	cin >> tam1;
	memset(dp, -1, sizeof dp);
	
	for(int i = 0; i < tam2; i++)
		cin >> b[i];

	int minimo = lcs(tam1-1);
	cout << tam1 << endl;
	/*for(int i = 0; i < tam1; i++) {
		for(int j = 0; j < tam2; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
    return 0;
}

