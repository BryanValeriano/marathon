#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int n, k;
const int TAM = 51;
int row[5][TAM];

struct mov {
	int car, i, j;
};

vector<mov> moves; 

//guarda o movimento
void move(int carro, int x, int y) {
	mov tmp;
	tmp.car = carro;
	tmp. i = x;
	tmp.j = y;
	moves.pb(tmp);
}

//rotaciona uma vez e retorna
//quantos estacionaram
int solve() {
	int tmp;
	int cont = 0;
	for(int i = 2; i <= 3; i++) {
		for(int j = n; j >= 1; j--) {
			if(i == 2 && row[i][j] != 0) {
				if(row[i][j] == row[i-1][j]) 
					{ move(row[i][j], i - 1, j); row[i][j] = 0; cont++;}
				else if(j != 1 && row[i][j-1] == 0) { 
					move(row[i][j], i, j -1);
					tmp = row[i][j];
					row[i][j] = 0;
					row[i][j-1] = tmp;
				}
				else if(j == 1 && row[i+1][j] == 0) {
					move(row[i][j], i+1, j);
					tmp = row[i][j];
					row[i][j] = 0;
					row[i+1][j] = tmp;
				}
			} else if(row[i][j] != 0) {
				if(row[i][j] == row[i+1][j])
					{ move(row[i][j], i + 1, j); row[i][j] = 0; cont++;}
				else if(j != n && row[i][j+1] == 0) {
					move(row[i][j], i, j + 1);
					tmp = row[i][j];
					row[i][j] = 0;
					row[i][j+1] = tmp;
				}
				else if(j == n && row[i-1][j] == 0) {
					move(row[i][j], i - 1, j);
					tmp = row[i][j];
					row[i][j] = 0;  
					row[i-1][j] = tmp;
				}
			}
		} 
	}
	return cont;
}


int main() {
    ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= 4; i++) 
		for(int j = 1; j <= n; j++) 
			cin >> row[i][j];

	//se tiver nenhum espaco vazio
	//e nenhum carro do lado de sua vaga
	//nao tem solucao
	int rest = k;	
	int test = solve();
	if(k == 2*n && test == 0) { cout << -1 << endl; return 0; }
	rest -= test;

	//enquantos existem carros nao estacionados
	//rotacione
	while(rest) {
		rest -= solve();
	}
	int fim = moves.size();
	cout << fim << endl;
	for(int i = 0; i < fim; i++)
		cout << moves[i].car << " " << moves[i].i << " " << moves[i].j << endl;

    return 0;
}

