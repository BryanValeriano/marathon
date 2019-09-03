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

int id[10];

void construct() {
	id[0] = 6;
	id[1] = 2;
	id[2] = 5;
	id[3] = 5;
	id[4] = 4;
	id[5] = 5;
	id[6] = 6;
	id[7] = 3;
	id[8] = 7;
	id[9] = 6;
}

int cont(int x) {
	int ans = 0;
	while(x) {
		ans += id[x % 10];
		x /= 10;
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	construct();
	int a, b; cin >> a >> b;
	ll ans = 0;
	for(int i = a; i <= b; i++) ans += cont(i);
	cout << ans << endl;
    return 0;
}
