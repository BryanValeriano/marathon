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
 
stack<ii> disponivel;	
stack<ii> matar;

int main() {
	ios_base::sync_with_stdio(false);
	int n, x; cin >> n;
	ll ans = 0;

	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x > 0) { ans += x; matar.emplace(i,x); }
		else disponivel.emplace(i,x);
	}

	if(ans < n) { 
		cout << "YES" << endl;
		while(!matar.empty()) {
			ii atual = matar.top();
			matar.pop();

			for(int j = 0; j < atual.se; j++) {
				cout << atual.fi << " " << disponivel.top().fi << endl;
				disponivel.pop();
			}
		
			disponivel.push(atual);
		}
	} else cout << "NO" << endl;
	

	return 0;
}


