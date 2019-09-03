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
	int row[(n/2) + 1];
	for(int i = 1; i <= n/2; i++) 
			row[i] = (n+n)*i;
	sort(row+1, row + (n/2) + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n/2; j++) {
			cout << i + (j > 1? row[j-1] : 0) << " " << (row[j] - (i-1)) << " "; 
		}
		cout << endl;
	}

    return 0;
}

