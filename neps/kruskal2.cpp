#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e4+3;

struct aresta {
	int x, y, dist;
};

int pai[105];
int peso[105];
aresta grafo[TAM];

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	
	if(peso[a] < peso[b]) pai[a] = b;
	else if(peso[a] > peso[b]) pai[b] = a;
	else {
		pai[b] = a;
		peso[a]++;
	}
}

bool cmp(aresta &a, aresta &b) { return a.dist < b.dist; }

int main() {
    ios::sync_with_stdio(false);
	int n,f,r;
	cin >> n >> f >> r;
	for(int i = 1; i <= n; i++) pai[i] = i;
	for(int i = 1; i <= f+r; i++)
		cin >> grafo[i].x >> grafo[i].y >> grafo[i].dist;

	sort(grafo + 1, grafo+f+r+1, cmp);

	ll qtd = 0;
	for(int i = 1; i <= f+r; i++) {
		if(find(grafo[i].x) != find(grafo[i].y)) {
			join(grafo[i].x, grafo[i].y);
			qtd += grafo[i].dist;
		}
	}
	cout << qtd << endl;


    return 0;
}

