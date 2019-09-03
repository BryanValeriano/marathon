#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
bool dp[1000][100];
const int n = 6;
int S[n] = {1, 1, 1, 2, 2, 3};


void check(int soma, int pos, int qtd) {
	if(pos > n) return; 
	if(dp[soma][qtd] == true) return;
	
	cout << soma << " " << pos << " " << qtd << endl;
	dp[soma][qtd] = true;

	check(soma + S[pos], pos + 1, qtd + 1);
	check(soma, pos + 1, qtd);
}

int main() {
    ios::sync_with_stdio(false);
	check(0, 0, 0);
	cout << dp[5][3] << endl;

	return 0;
}

