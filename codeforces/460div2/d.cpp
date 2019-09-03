#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 300000 + 10;
int graus[TAM];
vector<int>graph[TAM];
int dp[TAM][26];

int main() {
    ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	string row; cin >> row;
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graus[b]++;
	}
	vector<int>list;
	for(int i = 1; i <= n; i++) {
		if(graus[i] == 0) list.pb(i);
		dp[i][row[i - 1] - 97] = 1;
	}
	int ini = 0;
	int msum = 0;
	while(ini < list.size()) {
		int atual = list[ini];
		ini++;
		for(int i = 0; i < graph[atual].size(); i++) {
			int v = graph[atual][i];
			for(int j = 0; j < 26; j++) {
				dp[v][j] = max(dp[v][j], dp[atual][j] + ((row[v - 1] - 97) == j));
				msum = max(msum, dp[v][j]);
			}
			graus[v]--;
			if(graus[v] == 0) list.pb(v);
		}
	}
	cout << list.size() << endl;
	if(list.size() < n) { cout << -1 << endl; return 0; }
	else cout << msum << endl;

    return 0;
}

