#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e3+3;
int dp[TAM][60];

int valor[60];
int peso[60];

int knap(int capacidade, int qtd) {
	if(capacidade < 0) return -INF;
	if(qtd == 0) return 0;
	if(dp[capacidade][qtd] != -1) return dp[capacidade][qtd];
	
	int R = knap(capacidade - peso[qtd], qtd - 1) + valor[qtd];
	int L = knap(capacidade, qtd - 1);

	return dp[capacidade][qtd] = max(R,L);
}

int main() {
    ios::sync_with_stdio(false);
	int capacidade, qtd;
	cin >> capacidade >> qtd;
	int cont = 0;
	while(capacidade && qtd) {
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= qtd; i++)
			cin >> peso[i] >> valor[i];
		cout << "Teste" << " " << ++cont << endl;
		cout << knap(capacidade, qtd) << endl;
		cin >> capacidade >> qtd;
	}

    return 0;
}

