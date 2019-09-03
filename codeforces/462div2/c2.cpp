#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 2e4 + 3;
int dp[TAM][5];
int n;
int row[TAM];

int steve(int pos, int trocas, int flag, int last) {
	if(pos == n) return 0;
	if(trocas > 4) return 0;
	int &r = dp[pos][trocas];
	if(r != -1) return r;

	int ans = 0;
	if(flag == 1) {
		if(last != row[pos]) {
			ans = max(ans, steve(pos + 1, trocas + 1, flag, row[pos]) + (trocas + 1 > 4? 0 : 1));
			ans = max(ans, steve(pos + 1, trocas, 0, row[pos-1]));
		}	
		else ans = max(ans, steve(pos + 1, trocas, flag, row[pos]) + 1);
	}
	else {
		if(last != row[pos]) {
			int aux = 1;
			if(row[pos] == 2 && trocas == 0) aux = 2;
			ans = max(ans, steve(pos + 1, trocas + aux, 1, row[pos]) + (trocas + aux > 4? 0 : 1));
			ans = max(ans, steve(pos + 1, trocas, flag, last));
		}
		else ans = max(ans, steve(pos + 1, trocas, flag, last) + 1);
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

	int trocas = 1;
	if(row[0] == 2) trocas = 2;
	cout << max(steve(1, trocas, 1, row[0])+1, steve(1, 0, 0, row[0])) << endl;;
	return 0;
}

