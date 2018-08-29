#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int visitados[2005];

void dfs(int atual, vector<int> graph[]) {
	if(visitados[atual] == 1) return;
	visitados[atual] = 1;
	int vizinhos = graph[atual].size();
	for(int i = 0; i < vizinhos; i++) {
		dfs(graph[atual][i], graph);
	}
}

int main() {
    ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	while(n && m) {
		vector<int>graph[n+1];
		int a, b, aux;
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> aux;
			graph[a].pb(b);
			if(aux == 2) graph[b].pb(a);
		}
		int flag = 1;
		for(int i = 1; i <= n; i++) {
			memset(visitados, 0, sizeof visitados);
			dfs(i, graph);	
			for(int j = 1; j <= n; j++)
				if(visitados[j] == 0) flag = 0;
		}
		cout << flag << endl;
		cin >> n >> m;
	}
    return 0;
}

