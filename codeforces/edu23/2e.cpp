#include <bits/stdc++.h>
 
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 5100010;
 
int tr[N][2], qtd[N], cnt;
void insert (int p) {
	int at = 0;
	for (int i = 29; i >= 0; i--) {
		qtd[at]++;
        cout << at << " " << qtd[at] << endl;
		int v = p & (1 << i) ? 1 : 0;
		if (!tr[at][v]) tr[at][v] = ++cnt;
		at = tr[at][v];
	}
	qtd[at]++;
    cout << at << " " << qtd[at] << endl;
}
void erase (int p) {
	int at = 0;
	for (int i = 29; i >= 0; i--) {
		qtd[at]--;
		int v = p & (1 << i) ? 1 : 0;
		if (!tr[at][v]) tr[at][v] = ++cnt;
		at = tr[at][v];
	}
	qtd[at]--;
}
int search (int p, int l) {
	int at = 0;
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int v = l & (1 << i) ? 1 : 0;
		int k = p & (1 << i) ? 1 : 0;
 
		if (v) if (tr[at][k]) ans += qtd[tr[at][k]];
		if (!tr[at][v^k]) return ans;
		at = tr[at][v^k];
	}
	return ans;
}
int main (void) {
	int q; scanf("%d", &q);
	while (q--) {
		int t, p, l;
		scanf("%d %d", &t, &p);
		if (t == 1) insert(p);
		else if (t == 2) erase(p);
		else {
			scanf("%d", &l);
			//cout << search (p, l) << endl;
		}
	}
	return 0;
}
 
