#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e6;
int pai[TAM];
int peso[TAM];

int find(int x) {
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	
	if(x == y) return;

	if(peso[x] > peso[y]) {
		pai[y] = x;
	}
	else if(peso[y] > peso[x]) {
		pai[x] = y;
	}
	else { 
		pai[y] = x;
		peso[x]++;
	}
}

int main() {
    ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	memset(peso, 1, sizeof peso);
	for(int i = 1; i <= n; i++) 
		pai[i] = i;
	
	char op;
	int bancoA;
	int bancoB;

	while(k--) {
		cin >> op;
		cin >> bancoA >> bancoB;	
		if(op == 'F'){ 
			join(bancoA, bancoB);
		}
		else {
			if(find(bancoA) == find(bancoB)) cout << 'S';
			else cout << 'N';
			cout << endl;
		}
	}
    return 0;
}

