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
const int T = 1e5 + 10;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		maxi = max(v[i], maxi);
	}
	int ans = 1;
	int tmp = 0;
	for(int i = 0; i < n; i++) { 
		if(v[i] == maxi) tmp++;
		else tmp = 0;
		ans = max(ans,tmp);
	}
	cout << ans << endl;

    
    
    return 0;
}
