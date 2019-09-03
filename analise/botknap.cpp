#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 2e3;
ll Mat[TAM][TAM];
vector<int>resp;
bool track[TAM];

void constroi(int peso[], int valor[], int W, int n) {
	int x = W;
	int i = n;
	while(i >= 1) {
		if(Mat[i][x] == Mat[i-1][x-peso[i]] + valor[i]) {
			resp.pb(i);
			x = x - peso[i];
		}
		i--;
	}
}

ll mochila(int peso[], int valor[], int W, int n) {
	for(int x = 0; x <= W; x++) Mat[0][x] = 0;
	for(int i = 1; i <= n; i++) {
		for(int x = 0; x <= W; x++) {
			if(peso[i] > x) Mat[i][x] = Mat[i-1][x];
			else Mat[i][x] = max(Mat[i-1][x], valor[i] + Mat[i-1][x-peso[i]]);
		}
	}
	constroi(peso, valor, W, n);
	return Mat[n][W];
}
int main() {
    ios::sync_with_stdio(false);
	int W; cin >> W;
	int n; cin >> n;

	int peso[n+1]; int valor[n+1];
	for(int i = 1; i <= n; i++)
		cin >> peso[i] >> valor[i];
	
	cout << mochila(peso, valor, W, n) << endl;
	for(int i = 0; i < resp.size(); i++) 
		cout << resp[i] << " ";
	cout << endl;
    return 0;
}

