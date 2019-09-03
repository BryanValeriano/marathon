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

int lcs(int atual, int iter) {
	if(iter < 0 || atual < 0) return 1;
	if(dp[atual][iter] != -1) return dp[atual][iter];
	
	
	int R = lcs(atual, iter - 1);
	int L = 0;
	if(a[atual] >= a[iter]) L = 1 + lcs(iter, iter-1);
	return dp[atual][iter] = max(R,L);
}

int main() {
    ios::sync_with_stdio(false);
	int tam;
	cin >> tam;
	memset(dp, -1, sizeof dp);
	
	for(int i = 0; i < tam; i++)
		cin >> a[i];

	int melhor = 0;
	for(int i = tam; i > 0; i--)
		melhor = max(melhor, lcs(tam-i, tam- (i+1)));
	cout << melhor << endl;
	
    return 0;
}

