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
	int ind = -1;
	for(int i = 0; i < n; i++) {
		ind++;
		for(int j = 0; j < n; j++) {
			if(j == ind) cout << k << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}

    return 0;
}

