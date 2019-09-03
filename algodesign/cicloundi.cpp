#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 105;
bool flag = false;
int pai[T];
int proc[T];
int visitados[T];

bool ciclo(int x, int y) {
	//cout << "TESTE atual: " << x << " pai[atual]: " << pai[x] << " filho: " << y;
	if(pai[x] != y) { /*cout << " TRUE" << endl;*/ return true; }
	/*cout << " FALSE" << endl;*/ return false;
}

void dfs(int atual, vector<int>graph[]) {
	if(visitados[atual] == 1) return;
	visitados[atual] = 1;
	int tam = graph[atual].size();
	for(int i = 0; i < tam; i++) {
		int filho = graph[atual][i];
		//cout << "atual: " << atual << " filho: " << filho << endl;
		pai[filho] = atual;
		dfs(filho, graph);
		if(proc[filho] == 0) {
			if(ciclo(atual, filho)) flag = true;
		}
	}
	proc[atual] = 1;
}
int main() {
    ios::sync_with_stdio(false);
	int n, m;
	int tr = 0;
	int tc; cin >> tc;
	while(tc--) {
		cin >> n && cin >> m;
		flag = false;
		memset(pai, 0, sizeof pai);
		memset(proc, 0, sizeof proc);
		memset(visitados, 0, sizeof visitados);
		vector<int>graph[n+1];
		int u, v;
		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		dfs(0, graph);
		
		cout << (flag? 1 : 0) << endl;
	}
    return 0;
}

