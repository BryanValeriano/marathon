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
 
const int T = 1e5 + 3;
int v[T];
int n;
 
void solve() { 
	int cont = 0;
	for(int i = 2; i <= n; i++) {
		if(v[i]) continue;
		v[i] = ++cont;
		for(int j = i+i; j <= n; j += i) if(!v[j]) v[j] = cont;
	}
}
		
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;
	solve();
	for(int i = 2; i <= n; i++) cout << v[i] << " ";
	cout << endl;
    return 0;
}
