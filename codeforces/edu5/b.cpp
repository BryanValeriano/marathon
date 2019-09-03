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

 
int main() {
    ios_base::sync_with_stdio(false);
	int n,m,x,ans,mini;
	ans = 0;
	mini = INF;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int mini = INF;
		for(int j = 0; j < m; j++) {
			cin >> x;
			mini = min(mini, x);
		}
		ans = max(mini, ans);
	}
	cout << ans << endl;
    return 0;
}
