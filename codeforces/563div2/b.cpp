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
 
const int T = 1e5 + 5;
int v[T];
bool vis[T];
vector<int> pa;
vector<int> im;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;
	bool a = 0, b = 0;
 
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(v[i]&1) a = 1;
		else b = 1;
	}
	if(a and b) sort(v, v+n);
	for(int i = 0; i < n; i++) cout << v[i] << " ";
	cout << endl;
    return 0;
}
