#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 10;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n, greater<int>());
	ll melhor = v[0];
	ll seg = v[1];
	ll vezesM = k * (m/(k+1));
	ll vezesS = (m/(k+1));
	vezesM += (m - (vezesM + vezesS));
	ll ans = vezesM * melhor + vezesS * seg;
	//cout << vezesM << " " << melhor << " | " << vezesS << " " << seg << endl;
	cout << ans << endl;

    
    
    return 0;
}

