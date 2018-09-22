#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<ll> row;
	vector<ll> row2;
	ll aux;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		row.pb(aux);
	}

	for(int i = 0; i < m; i++) {
		cin >> aux;
		row2.pb(aux);
	}


	ll maxx = -INF;
	int pos = 0;
	for(int i = 0; i < row.size(); i++) 
		for(int j = 0; j < row2.size(); j++) { 
			if(maxx < row[i] * row2[j]) {
				maxx = row[i] * row2[j];
				pos = i;
			}
		}
	row.erase(row.begin() + pos);
	maxx = -INF;
	for(int i = 0; i < row.size(); i++) 
		for(int j = 0; j < row2.size(); j++)  
			maxx = max(maxx, row[i] * row2[j]);
		
	cout << maxx << endl;
    return 0;
}

