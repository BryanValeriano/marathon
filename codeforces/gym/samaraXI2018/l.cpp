#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 5;
int nxt[T][30];
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	s = 'a' + s;

	memset(nxt, -1, sizeof nxt);
	int n = s.size();

	for(int i = n-1; i >= 1; i--) {
		for(int j = 0; j < 30; j++) nxt[i-1][j] = nxt[i][j];
		nxt[i-1][s[i]-'a'] = i;
	}

	int x = 0;
	int m; cin >> m;
	int vezes = 0;
	stack<int> z;

	while(m--) {
		string op; cin >> op;
		if(op == "push") {
			char k; cin >> k;
			if(vezes) { vezes++; cout << "NO" << endl; continue; }
			if(nxt[x][k-'a'] != -1) cout << "YES" << endl, z.push(x),  x = nxt[x][k-'a'];
			else cout << "NO" << endl, vezes++;
		} else {
			if(vezes) { 
				vezes--;
				cout << (vezes == 0? "YES" : "NO") << endl;
			} else { 
				cout << "YES" << endl, x = z.top(); 
				z.pop();
			}
		}
	}
    
    
    return 0;
}

