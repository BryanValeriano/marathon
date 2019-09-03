#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAN = 2e5;
int graus[TAN];

int main() {
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int>graph[n];
	vector<int>list;
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graus[b]++;
	}
	for(int i = 0; i < n; i++) if(graus[i] == 0) list.pb(i);	
	int cont = 0;
	sort(list.begin(), list.end());
	while(cont < list.size()) {
		int atual = list[cont];
		cont++;
		for(int i = 0; i < graph[atual].size(); i++) {
			int v = graph[atual][i];
			graus[v]--;
			if(graus[v] == 0) {
				int j = cont;
				while(v > list[j] && j < list.size()) j++; 
				list.insert(list.begin() + j, v);
			}
		}
	}
	if(list.size() < n) { cout << "*" << endl; return 0; }
	for(int i = 0; i < n; i++)
		cout << list[i] << endl;
    return 0;
}
