#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	int maxx = -INF;
	while(n--) {
		int f, t; cin >> f >> t;
		int tmp = f - max(0, t - k);
		maxx = max(tmp, maxx);
	}
	cout << maxx << endl;
    return 0;
}

