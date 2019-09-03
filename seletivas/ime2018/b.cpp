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
	for(int i = 0; i < n; i++) 
		cin >> row[i];
	//sort(row, row + n);
	//test k != n
	int metade  = (n>>1)+1;
	for(int k = 2; k <= metade; k++) 
		if(n%k == 0) {
			map<int,int>ind;
			int gol = n/k;
			for(int i = 0; i < n; i++){
				int tmp = ++ind[row[i]%k];
				//cout << "K: " << k << " resto: " << row[i]%k <<" tmp: " << tmp << " Gol: " << gol << "row[i]: " << row[i] << endl;
				if(tmp == gol) {
					cout << k << endl;
					return 0;
				}
			}
		}
	int k = n;
	map<int,int>ind;
	int gol = n/k;
	for(int i = 0; i < n; i++){
		int tmp = ++ind[row[i]%k];
		if(tmp == gol) {
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}

