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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e4 + 10;
int a[T];
int b[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int ans = 1;
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

	int ai = 0;
	int bi = 0;
	int i = 0;
	while(i < n) {
		if(a[i] >= bi and a[i] <= b[i]) {
			ans += (a[i] - max(bi,ai) + 1);
			if(ai == bi) ans--;
			//a[i]++;
		}
		else if(b[i] >= ai and b[i] <= a[i]) {
			ans += (b[i] - max(ai,bi) + 1);
			if(ai == bi) ans--;
			//b[i]++;
		}
		
		ai = a[i];
		bi = b[i];
		i++;
	} 
	cout << ans << endl;
    return 0;
}
