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
	int maxx = 0;
	int a, b;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		maxx = max(maxx, a+b);
	}
	cout << maxx << endl;

    return 0;
}

