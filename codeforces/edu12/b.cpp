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
 
deque<int> fila;

int pos(int x) {
	for(int i = 0; i < fila.size(); i++) 
		if(fila[i] == x) return i;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n,m,k;
	int x;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		cin >> x;
		fila.push_back(x);
	}
	int ans = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> x;
			int y = pos(x);
			ans += y + 1;
			fila.erase(fila.begin() + y);
			fila.push_front(x);
		}
	}

	cout << ans << endl;
    
    
    return 0;
}
