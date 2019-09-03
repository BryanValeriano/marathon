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

const int T = 110;
int v[T];
int ans[T];
bool vis[T];
int n, m;

int f(int a, int b) {
	for(int i = 1; i <= n; i++) 
		if((a+i)%n == b) return i;
}

bool check() {
	int i = v[0];
	int j = 0;

	for(int i = 0; i < n; i++) vis[ans[i]] = 1;

	for(int i = 1; i <= n; i++) if(!vis[i]) return false;
	memset(vis, 0, sizeof vis);

	while(j < m) {
		vis[i] = 1;
		if(i != v[j]) return false;	
		i = (i+ans[i-1])%n;
		if(i == 0) i = n;
		j++;
	}

	return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		cin >> v[i];
		v[i]--;
	}
	
	if(n == 1) {
		for(int i = 0; i < m; i++) if(v[i] != 0) {
			cout << -1 << endl;
			return 0;
		}
		cout << 1 << endl;	
		return 0;
	}

	for(int i = 1; i < m; i++) {
		ans[v[i-1]] = f(v[i-1], v[i]);
		vis[ans[v[i-1]]] = 1;
	}

	for(int i = 0; i < n; i++) {
		if(!ans[i]) {
			for(int j = 1; j <= n; j++) {
				if(!vis[j]) {
					ans[i] = j;
					vis[j] =1;
					break;
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++) v[i]++;	
		
	memset(vis, 0, sizeof vis);
	if(check()) {
		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}

    return 0;
}
