#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 10;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	int menorA = 0;
	int maiorA = INF;
	int menorB = 0;
	int maiorB = INF;

	int x = v[0];
	int y = v[n-1];
	for(int i = 1; i < n; i++) {
		maiorA = min(maiorA, (x+v[i])-1);
		menorA = max(menorA, (max(x,v[i])+1) - min(x,v[i]));
	}
	for(int i = n-2; i >= 0; i--) {
		maiorB = min(maiorB, (v[i]+y)-1);
		menorB = max(menorB, (max(v[i],y)+1) - min(v[i],y));
	}

	menorA = max(menorA, menorB);
	maiorA = min(maiorA, maiorB);

	if(menorA > maiorA) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << menorA << endl;
	}
    
    return 0;
}
