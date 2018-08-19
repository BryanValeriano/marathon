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
	int row[n];
	int mini = INF;
	int melhor;
	for(int i = 0; i < n; i++) {
		cin >> row[i];
		int k = i;
		while(row[i] - k > 0) k += n;
		if(mini > k) {
			mini = k;
			melhor = i;
		}
	}
	cout << melhor+1 << endl;
    return 0;
}

