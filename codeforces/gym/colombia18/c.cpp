#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int N = 180;
ll dist[N][N];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	string s, t;
	cin >>s >>t >>n;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dist[i][j] = INF;
	
	for(int i = 0; i < N; i++) dist[i][i] = 0;

	for(int i = 0 ; i< n; i++) {
		char a, b;
		ll v;
		cin >> a >> b >> v;
		dist[a][b] = min(dist[a][b], v);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(dist[s[i]][t[i]] >= INF) {
			cout <<-1 <<endl;
			return 0;
		}
	}
	for(int i = 0; i < s.size(); i++) ans += (dist[s[i]][t[i]]);
	cout <<ans <<endl;
	
	return 0;
}
 
