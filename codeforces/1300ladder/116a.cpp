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
	int n; cin >> n;
	int maxi = 0;
	int aux = 0;
	int a, b;
	while(n--) {
		cin >> a >> b;
		aux -= a;
		aux += b;
		maxi = max(maxi, aux);
	}

	cout << maxi << endl;
    return 0;
}

