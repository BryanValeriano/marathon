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
	for(int i = 0; i <= n; i++) 
		row[i] = i;
	for(int i = 0; i <= 2*n; i++) {
		for(int j = 0; j < 2 * abs(n-i); j++) 
			cout << " ";
		for(int j = 0; j <= (i <= n? i : i == 2*n? 0 : n - (i % n)); j++) {
			cout << row[j];
			if(i != 0 and i != 2*n) cout << " ";
		}
		for(int j = (i <= n? i : i == 2*n? 0 : n - (i % n)) - 1; j >= 0; j--) {
			cout << row[j]; 
			if(j - 1 >= 0) cout << " ";
		}
		cout << endl;
	}

    return 0;
}

