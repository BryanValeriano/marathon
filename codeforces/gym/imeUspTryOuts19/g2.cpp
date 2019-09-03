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

const int T = 1e5 + 2;
int poder[T], pai[T];
int n, q;

int find(int x) {
	if(x == pai[x]) return x;
	int nxt = find(pai[x]);
	poder[x] = min(poder[x], poder[pai[x]]);
	return pai[x] = nxt;
}

void join(int x, int y) {
	if(find(x) == find(y)) return;
	pai[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	char op;
	int a,b;

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> poder[i];
		pai[i] = i;
	}

	while(q--) {
		cin >> op >> a;
		if(op == '+') {
			cin >> b;
			join(a,b);
		} else find(a), cout << poder[a] << endl;
	}

    return 0;
}

