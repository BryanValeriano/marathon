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

const int T = 110;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a = 0,b = 0;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		if(v[i] == 1) a++;
		else b++;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int aa = a;
		int bb = b;
		for(int j = -n; j <= n; j++) {
			if(i + j*k >= 1 and i + j*k <= n) {
				if(v[i + j*k] == 1) aa--;
				else bb--;
			}
		}
		ans = max(ans, abs(aa-bb));
	}
	

	cout << ans << endl; 
    
    return 0;
}
