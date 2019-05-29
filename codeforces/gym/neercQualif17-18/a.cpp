#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 105;
bool vis[T];
int ant[T];
int nxt[T];

int dfs(int at) {
	while(!vis[nxt[at]]) { 
		vis[at] = 1;
		if(nxt[at]) at = nxt[at];
		else break;
	}
	return at;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;

	queue<int> lista;

	for(int i = 1; i <= n; i ++) {
		cin >> ant[i] >> nxt[i];
		if(!ant[i]) lista.push(i);
	}

	int last = 0;
	while(!lista.empty()) { 
		int at = lista.front();
		lista.pop();
		vis[at] = 1;
		ant[at] = last;
		nxt[last] = at;
		last = dfs(at);
	}

	for(int i = 1; i <= n; i++) cout << ant[i] << " " << nxt[i] << endl;
    
    return 0;
}
