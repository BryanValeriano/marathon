#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int TAM = 103;
int mat[TAM][TAM];
int dist[TAM][TAM];
int n;

void dij(int lin, int col) {
	memset(dist, INF, sizeof dist);	
	priority_queue<pii, vector<pii>, grater<pii> fila;
	dist[lin][col] = 0;
	fila.push(dist[lin][col],

int main() {
    ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
			cin >> mat[i][j];

	dij(0,0);	

    return 0;
}

