#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 
 
typedef long long ll;
typedef pair<int,int> ii;
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 105;
ll ac[N][N];
bool tem[N][N];
int n,m;
 
ll dist(int a, int b) {
	ll ans = 0;
	bool flag = 1;
	for(int i = 1; i <= m; i++)	
		if(tem[a][i] and tem[b][i]) flag = 0, ans += (ac[a][i] - ac[b][i]) * (ac[a][i] - ac[b][i]);
	return (flag? INF : ans);
}
 
int melhor(int a, int b) {
	ll best = -1;
	int id = -1;
	for(int i = 1; i <= m; i++) 
		if(!tem[a][i] and tem[b][i]) {
			if(ac[b][i] > best) {
				best = ac[b][i];
				id = i;
			}
		}
	return id;	
}
 
int main(void) {
	ios::sync_with_stdio(false);
 
	ll curso, nota;
 
	cin >>n >>m;
	for(int i = 1; i <= n; i++) {
		int ok; cin >> ok;
		for(int j = 1; j <= ok; j++) {
			cin >> curso >> nota;
			ac[i][curso] = nota;
			tem[i][curso] = 1;
		}
	}
 
	for(int i = 1; i <= n; i++) {	
		int id = 0;
		ll best = INF;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			ll close = dist(i,j);
			if(close < best) best = close, id = j;
		}
		cout << melhor(i,id) << endl;
	}
 
	return 0;
}
