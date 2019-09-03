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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 1e5 + 5;
int v[T];
ll cresc[T];
ll dc[T];
ll cresc2[T];
ll dc2[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> v[i];

	for(int i = 2; i <= n; i++) 
		if(v[i] <= v[i-1] + cresc[i-1]) cresc[i] = (v[i-1] + cresc[i-1] + 1) - v[i];

	for(int i = n-1; i >= 1; i--) 
		if(v[i] <= v[i+1] + dc[i+1]) dc[i] = (v[i+1] + dc[i+1] + 1) - v[i];

	for(int i = 1; i <= n; i++) {
		cresc2[i] = cresc[i];
		cresc[i] += cresc[i-1];
	}
	for(int i = n-1; i >= 1; i--) {
		dc2[i] = dc[i];
		dc[i] += dc[i+1];
	}
	
	
	ll ans = (n == 1? 0LL : INF);

	for(int i = 0; i <= n; i++) {
		ans = min(ans, cresc[i] + dc[i+1] + (v[i] + cresc2[i] == v[i+1] + dc2[i+1]? 1: 0));
	}

	cout << ans << endl;
    
    return 0;
}
