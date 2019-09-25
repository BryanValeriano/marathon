#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 10;
int n,m;
vii edg;

int solve(int at) {
	set<ii> bag;
	set<int> corn;
	set<int> g[T];
	int qtd[T];
	memset(qtd,0,sizeof qtd);

	int a,b;
	for(int i = 0; i < m; i++) {
		tie(a,b) = edg[i];

		if(a == 7) a = at;
		else if(a == at) a = 7;
		if(b == 7) b = at;
		else if(b == at) b = 7;


		if(a <= 6 and b <= 6) {
			bag.emplace(min(a,b),max(a,b));
			g[b].insert(a); g[a].insert(b);
		} else corn.insert(min(a,b));
	}

	int maxi = 0;
	for(auto ok : corn) {
		for(int j = 1; j <= 6; j++) {
			if(!g[ok].count(j)) qtd[j]++, maxi = max(maxi,qtd[j]);
		}
	}

	return bag.size() + maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		edg.eb(a,b);
	}

	int ans = 0;
	for(int i = 1; i <= 7; i++) ans = max(ans,solve(i));
	cout << ans << endl;

    return 0;
}
