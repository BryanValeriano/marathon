#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int LOG = 20;
const int T = 1e5 + 2;

int pai[T][LOG];
int temp[T][LOG];
int inter[T][LOG];
int poder[T];
vii qer;
int n,m;

int query(int node, int t) {
	int ans = poder[node];

	for(int i = LOG-1; i >= 0; i--) {
		if(temp[node][i] <= t) {
			ans = min(ans,inter[node][i]);
			node = pai[node][i];
		}
	}

	return ans;
}

int main(void) {
    scanf("%d %d\n", &n, &m);
	memset(temp, INF, sizeof temp);
	memset(inter, INF, sizeof inter);

	for(int i = 1; i <= n; i++) scanf("%d ", &poder[i]);
	char op;
	int a,b;


	for(int i = 1; i <= m; i++) {
        scanf("%c %d", &op, &a);
		if(op == '+') {
            scanf("%d", &b);
			qer.eb(a,b);
			pai[b][0] = a;
			temp[b][0] = i;
		}
		else qer.eb(0,a);
        scanf("\n");
	}

	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= n; i++)
			pai[i][j] = pai[pai[i][j-1]][j-1];

	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= n; i++)
			temp[i][j] = max(temp[i][j-1], temp[pai[i][j-1]][j-1]);

	for(int i = 1; i <= n; i++)
		inter[i][0] = min(poder[i], pai[i][0] ? poder[pai[i][0]] : INF);

	for(int j = 1; j < LOG; j++)
		for(int i = 1; i <= n; i++)
			inter[i][j] = min(inter[i][j-1], pai[i][j-1] ? inter[pai[i][j-1]][j-1] : INF);

	for(int i = 0; i < qer.size(); i++) {
		ii q = qer[i];
		if(q.fi == 0) printf("%d\n", query(q.se,i+1));
	}

	return 0;
}
