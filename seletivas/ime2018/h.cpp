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
	int n, q;
	cin >> n >> q;
	int row[n];
	for(int i = 1 ; i <= n; i++) 
		cin >> row[i];
	while(q--) {
		int maxx = 0;	
		int ini, fim;
		map<int,int>ind;
		cin >> ini >> fim; 
		for(int i = ini; i <= fim; i++) {
			int tmp= ind[row[ini]]++;
			if(row[ini] ==  tmp) {
				maxx = max(maxx, tmp);
			}
		}
		cout << maxx << endl;

	}
    return 0;
}

