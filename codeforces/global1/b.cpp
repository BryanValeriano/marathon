#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
vector<int> v;
bool vis[T];
 
int main(){
    ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	int last, at;
	cin >> last;
	for(int i = 1; i < n; i++) {
		cin >> at;
		v.pb(at-last);
		last = at;
	}
	sort(v.begin(), v.end());
	int tira = n-k;
	ll ans = k;
	for(int i = 0; i < tira; i++) ans += v[i];
	cout << ans << endl;
    return 0;
}
