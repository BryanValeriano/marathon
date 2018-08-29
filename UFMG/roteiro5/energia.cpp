#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 110;
int visitados[T];

void dfs(int atual, vector<int> graph[]) {
	if(visitados[atual] == 1) return;
	visitados[atual] = 1;
	int tam = graph[atual].size();
	for(int i = 0; i < tam; i++) 
		dfs(graph[atual][i], graph);
}

int main() {
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int cont = 0;
	while(n || m) {
		vector<int>graph[n+1];
		int u, v;
		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			memset(visitados, 0, sizeof visitados);
			dfs(i, graph);
			for(int j = 1; j <= n; j++) 
				if(visitados[j] == 0) flag = false;
		}
		cout << "Teste " << ++cont << endl;
		cout << (flag? "normal" : "falha") << endl << endl;
		cin >> n >> m;
	}
		
    return 0;
}

