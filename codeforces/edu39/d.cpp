#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 510;
string dia[T];
int pega[T][T];
int dp[T][T];
int n,k;
int tot;

int solve(int at, int qtd) {
    if(qtd > k) return INF;
	if(at == n) return 0;

	if(dp[at][qtd] != -1) return dp[at][qtd];

	int ans = solve(at+1, qtd + pega[at][0]);
	
	for(int i = 1; i <= pega[at][0]; i++) 
		if(qtd + pega[at][0] - i <= k) ans = min(ans, solve(at+1, qtd + pega[at][0] - i) + pega[at][i]);
	
	return dp[at][qtd] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

    memset(pega, INF, sizeof pega);
	memset(dp, -1, sizeof dp);

	int m; cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> dia[i];	

	for(int i = 0; i < n; i++) { 
        vector<int> ponta;

		for(int j = 0; j < m; j++) if(dia[i][j] == '1') ponta.pb(j);
		
        tot += ponta.size();
        pega[i][0] = ponta.size();

        for(int j = 0; j < ponta.size(); j++) 
            for(int p = j; p < ponta.size(); p++) 
                pega[i][p - j + 1] = min(pega[i][p - j + 1], ponta[p] - ponta[j] + 1);
	}
    k = min(k,tot);
	cout << solve(0,0) << endl;	
    return 0;
}

