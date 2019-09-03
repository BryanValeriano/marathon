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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vii v;
 
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m;
	int maior = 0, menor = 0;
	
	while(n--) {
		cin >> x;
		(x >= m)? ++maior : ++menor;
		if(maior > menor) v.eb(maior,menor), maior = menor = 0;
	}

	while ((maior or menor) and v.size()) {	
		ii at = v.back();
		v.pop_back();
		maior += at.fi;
		menor += at.se;
		if(maior > menor) { v.eb(maior,menor); maior = menor = 0; break; }
	}
	
	cout << v.size() << endl;

	return 0;
}

