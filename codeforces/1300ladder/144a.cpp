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
	pair<int,int> mini = mk(INF,0);
	pair<int,int> maxi = mk(0, 0);
	int aux;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		if(aux <= mini.fi) {
			mini.fi = aux;
			mini.sec = i;
		}
		if(aux > maxi.fi) {
			maxi.fi = aux;
			maxi.sec = i;
		}
	}
	int ans = 0;
	if(maxi.sec > mini.sec) ans--;	

	cout << maxi.sec + ((n - 1) - mini.sec) + ans << endl;
    return 0;
}

