#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 2e3;
int qtd;
int dp[TAM][TAM];
int peso[TAM];
int valor[TAM];
int track[TAM];

ll bk(int resist, int pos) {
	cout << resist << " " << pos << " " << valor[pos] << endl;
	if(resist < 0) return -INF;
	if(pos == qtd) return 0;
	if(dp[pos][resist] != -1) return dp[pos][resist];

	ll R = bk(resist - peso[pos], pos + 1) + valor[pos];
	ll L = bk(resist, pos + 1);
	
	return dp[pos][resist] = max(R,L);
}

int main() {
    ios::sync_with_stdio(false);
	int resist; cin >> resist;
	cin >> qtd;
	memset(dp, -1, sizeof dp);

	for(int i = 0; i < qtd; i++) 
		cin >> peso[i] >> valor[i];
	cout << bk(resist, 0) << endl; 
	for(int i = 0; i < qtd; i++) cout << track[i] << " ";
	cout << endl;
    return 0;
}

