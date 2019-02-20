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
ll X[T];
ll Y[T];
ll inix, iniy, fimx, fimy;
int n;

ll manha(ll x, ll y) {
	return (abs(fimx - x) + abs(fimy - y));
}

bool chega(ll t) {
	ll locX = 0;
	ll locY = 0;
	if(t > n) {
		locX += (t/n) * (X[n] - X[0]);
		locY += (t/n) * (Y[n] - Y[0]);
		locX += X[t%n]; // - X[0];
		locY += Y[t%n]; // - Y[0];
	} else {
		locX = X[t];
		locY = Y[t];
	}
	//cout << t << endl;
	//cout << locX << " " << locY << " | " << manha(locX, locY) << " " << (manha(locX, locY) <= t) << endl;
	return manha(locX, locY) <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> inix >> iniy >> fimx >> fimy;
	cin >> n;
	char tmp;
	X[0] += inix;
	Y[0] += iniy;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		if(tmp == 'U') Y[i]++;
		if(tmp == 'D') Y[i]--;
		if(tmp == 'L') X[i]--;
		if(tmp == 'R') X[i]++;
	}
	for(int i = 1; i <= n; i++) {
		X[i] += X[i-1];
		Y[i] += Y[i-1];
	}
	ll l = 0;
	ll r = 2e18;

	while(l <= r) {
		ll mid = (l+r) >> 1;
		if(chega(mid)) r = mid - 1;
		else l = mid + 1;
	}

	cout << (l >= 2e18-100? -1 : l) << endl;

    
    return 0;
}
