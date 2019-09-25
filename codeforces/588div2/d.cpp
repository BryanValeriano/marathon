#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 7005;

map<ll,int> qtd;
ll a[T];
ll b[T];
bool vis[T];
int n;
ll ans;

ll monta(ll x) {
	ll ok = 0;
	for(int i = 0; i < n; i++)
		if((a[i]&x) == a[i] and !vis[i]) ok += b[i], vis[i] = 1;
	return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++) cin >> a[i], qtd[a[i]]++;
	for(int i = 0; i < n; i++) cin >> b[i];


	for(auto ok : qtd)
		if(ok.se >= 2)
			ans += monta(ok.fi);

	cout << ans << endl;
    return 0;
}
