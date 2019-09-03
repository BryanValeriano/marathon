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
 
const int T = 1e3 + 5;
int v[T*2];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < 2*n; i++) cin >> v[i];
	sort(v,v+2*n);
	ll a = 0;
	ll b = 0;
	for(int i = 0; i < 2*n; i++) {
		if(i < n) a += v[i];
		else b += v[i];
	}
 
	if(a == b) { cout << -1 << endl; return 0; }
	for(int i = 0; i < 2*n; i++) cout << v[i] << " ";
	cout << endl;
 
    
    
    return 0;
}
