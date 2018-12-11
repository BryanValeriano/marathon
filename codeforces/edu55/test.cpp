#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool cmp(vector<int> v, vector<int> q) {
	if(v.size() > q.size()) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >>n >>m;
	
	const int N = 1e5 + 5;
	vector<int> v[N];
	
	for(int i = 0; i < n; i++) {
		int s, r;
		cin >>s >>r;
		v[s-1].pb(r);
	}
	for(int i = 0; i <= m; i++) {
		sort(v[i].begin(), v[i].end(), greater<int>());
	}
	
	for(int i = 0; i < m; i++) {
		for(int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j-1];
		}
	}

	sort(v, v+m, cmp);
	int maior = v[0].size();
	
	int fim = m;
	
	int ans = 0;
	for(int i = 0; i < maior; i++) {
		int sum = 0;
		for(int j = 0; j < fim; j++) {
			if(i >= v[j].size()) fim = j;
			else sum += v[j][i];
		}
		ans = max(ans, sum);
	}
	
	cout <<ans <<endl;
	return 0;
}
