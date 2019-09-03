#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 105;
int cor[T];

void colore(int x, vector<int>graph[]) {
	cor[x] = 0;
	vector<int>list;
	list.pb(x);
	int pos = 0;
	while(pos < list.size()) {
		int atual = list[pos];
		pos++;
		for(int i = 0; i < graph[atual].size(); i++) {
			int vizinho = graph[atual][i];
			if(cor[vizinho] == -1) {
				cor[vizinho] = 1 - cor[atual];
				list.pb(vizinho);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	int n, m;
	int cont = 0;
	while(cin >> n && cin >> m) {
		vector<int>graph[n+1];
		int u, v;
		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		memset(cor, -1, sizeof cor);
		for(int i = 1; i <= n; i++) 
			if(cor[i] == -1) colore(i, graph);
		bool flag = true;
		for(int i = 1; i <=n; i++)
			for(int j = 0; j < graph[i].size(); j++)
				if(cor[i] == cor[graph[i][j]]) flag = false;
		cout << "Instancia " << ++cont << endl;
		cout << (flag? "sim" : "nao") << endl << endl;
	}
    return 0;
}

