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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 3e5 + 3;
vector<int> g[T];
int pai[T];
bool nodeT[T];
bool aresta[T];
vector<int> edg;
int n,m;

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int a,b,c;
    init();
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(c) aresta[edg.size()] = 1;
		g[a].pb(edg.size());
		edg.eb(a,b);
	}



    return 0;
}

