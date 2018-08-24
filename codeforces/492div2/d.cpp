#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int row[202];
int n;

int find(int ini, int alvo) {
	for(int i = ini; i < n*2; i++) 
		if(row[i] == alvo) return i;
}

int troca(int ini, int fim) {
	int tmp;
	int trocas = 0;
	for(int i = fim; i > ini; i--) {
		tmp = row[i];	
		row[i] = row[i-1];
		row[i-1] = tmp;
		trocas++;
	}
	return trocas;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n*2; i++)
		cin >> row[i];

	int trocas = 0;
	for(int i = 0; i < (n*2)-1; i += 2) {
		if(row[i] != row[i+1]) {
			int pos = find(i+1, row[i]);
			trocas += troca(i+1, pos);
		}
	}
	cout << trocas << endl;
    return 0;
}

