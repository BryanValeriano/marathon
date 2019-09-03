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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
int v[T];
ll aparece[T];
ll pass[T];
ll n,k;

bool bin(int i) {
	ll foi = (pass[i] * (pass[i]-1))/ 2;

	ll l = 0;
	ll r = n;

	if(aparece[i] == k) return true;

	while(l <= r) {
		ll mid = (l+r) >> 1;
		ll val = ((mid)*(mid+1))/2;
		val -= foi;
		if(val + aparece[i] > k) r = mid-1;
		else if(val + aparece[i] < k) l = mid+1;
		else return true;
	}
	return ((l == k) or (r == k));
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;
	ll passo = 1;
	ll at;

	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		pass[i] = passo;
		aparece[i] = aparece[i-1] + passo;
		if(bin(i)) { cout << v[i] << endl; return 0; }
	}




    return 0;
}

