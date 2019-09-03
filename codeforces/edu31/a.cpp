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
 
const int T = 103;
int v[T];
int n,t;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> t;
	int x;
 
	for(int i = 1; i <= n; i++) {
		cin >> x;
		v[i] = 86400 - x;
		v[i] += v[i-1];
		if(v[i] >= t) {
			cout << i << endl;
			return 0;
		}
	}
 
    
    
    return 0;
}
