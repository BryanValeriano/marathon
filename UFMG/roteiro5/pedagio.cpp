#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int profun;
set<int>track;
int visitados[55];

void dfs(int atual, int altura, vector<int>graph[]) {
	if(visitados[atual] == 1) return;
	if(altura > profun) return;
	visitados[atual] = 1;
	if(altura != 0) track.insert(atual);
	int tam = graph[atual].size();
	for(int i = 0; i < tam; i++) {
		int filho = graph[atual][i];
		dfs(filho, altura + 1, graph);
	}
}

int main() {
    ios::sync_with_stdio(false);
	int n, m, ini;
	cin >> n >> m >> ini >> profun;
	int cont = 0;
	while(n) {
		vector<int>graph[n+1];
		int u, v;
		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		memset(visitados, 0, sizeof visitados);
		dfs(ini, 0, graph);
		cout << "Teste " << ++cont << endl;
		set<int>::iterator it;	
		set<int>::iterator it2;	
		for(it = track.begin(); it != track.end(); it++) {
			cout << *it;
                        it2 = it; it2++; 
                        if(it2 != track.end()) cout << " ";
                }
		cout << endl << endl;
		track.clear();
		cin >> n >> m >> ini >> profun;
	}
    return 0;
}

