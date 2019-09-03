#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

 
int main() {
	ios_base::sync_with_stdio(false);
	int n,m;
	int impar = 0;
	int par = 0;
	int impar2 = 0;
	int par2 = 0;
	int x;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x&1) impar++;
		else par++;
	}

	for(int i = 0; i < m; i++) {
		cin >> x;
		if(x&1) impar2++;
		else par2++;
	}

	int ans = min(impar2,par) + min(impar,par2);

	cout << ans << endl;	

	return 0;
}
