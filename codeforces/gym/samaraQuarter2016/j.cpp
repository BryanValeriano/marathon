#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;

	for(int i = 1; i <= n; i++) cin >> v[i];

	ll ans = 0;

	for(int i = 1; i <= n; i++) if(v[i] > v[i-1]) ans += v[i] - v[i-1]; 
	cout << ans << endl;
    
    return 0;
}

