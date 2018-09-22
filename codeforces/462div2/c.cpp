#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 2e4 + 3;
int dp[TAM][4];
int n;
int row[TAM];
int aux[4];

int steve(int pos, int trocas) {
	if(pos == n) return 0;
	if(trocas > 3) return 0;
	int &r = dp[pos][trocas];
	if(r != -1) return r;

	int ans = 0;
	if(row[pos] == aux[trocas])
		ans = max(ans, steve(pos + 1, trocas) + 1);
	else {
		ans = max(ans, steve(pos + 1, trocas));
		ans = max(ans, steve(pos + 1, trocas + 1) + (trocas + 1 > 3? 0 : 1));
	}

	return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> row[i];
	}
	memset(dp, -1, sizeof dp);
	aux[0] = aux[2] = 1;
	aux[1] = aux[3] = 2;

	cout << steve(0, 0) << endl;

	return 0;
}

