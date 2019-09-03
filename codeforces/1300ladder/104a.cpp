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
	n -= 10;
	if(n == 10) cout << 15;
	else if(n > 11) cout << 0;
	else if(n > 0) cout << 4;
	else cout << 0;
	cout << endl;

    return 0;
}

