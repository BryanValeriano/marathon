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
	int n, k;
	cin >> n >> k;

	int rest = k % ((n * (n+1))/ 2);
	for(int i = 1; i <= n; i++) {
		if(rest - i < 0) break;
		else rest -= i;
	}
	cout << rest << endl;
    return 0;
}

