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

struct node {
	int p, i, j;
};

bool cmp(node a, node b) {
	return a.p > b.p;
}

vector<node> v;

int calc(int i, int j) {
	for(auto at:v) {
		if(at.i != i and at.j != j) 
			return at.p;
	}
}


int calc2(int i, int j) {
	for(auto at:v) {
		if(at.i != i and at.j != j) 
			return (i<0? at.i:at.j);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >>n >>m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int p; cin >>p;
			v.pb(node({p, i, j}));
		}
	}

	sort(v.begin(), v.end(), cmp);
	
	int i1, j1, i2, j2;
	i1 = v[0].i;
	j1 = calc2(i1, -1);

	j2 = v[0].j;
	i2 = calc2(-1, j2);

	
	int ans1 = calc(i1, j1);
	int ans2 = calc(i2, j2);
	
	//cout <<(ans1 < ans2? i1+1:i2+1) <<' ' <<(ans1 < ans2? j1+1:j2+1) <<endl;
	if(ans1 < ans2) cout <<i1+1 <<' ' <<j1+1 <<endl;
	else cout <<i2+1 <<' ' <<j2+1 <<endl;

	return 0;
}


