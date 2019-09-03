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
const ll INF = 0x3f3f3f3f3f;

ll x1, Y1, x2, y2, vx1, vY1, vx2, vy2;

double pow(double n, double exp) {
	double ans = 1;
	while(exp) {
		ans *= n;
		exp--;
	}
	return ans;
}
double f(double t) {
	return hypotf(abs(x1 + vx1*t - (x2 + vx2*t)), abs(Y1 + vY1*t - (y2 + vy2*t)));
}

double ternary_search(double lo, double hi) {
	double  eps = 1e-10;
	while(hi - lo > eps) {
		double m1 = lo + (hi - lo)/3;
		double m2 = hi - (hi - lo)/3;
		if(f(m1) > f(m2))
			lo = m1;
		else
			hi = m2;
	}
	return f(lo);
}

int main() {
    ios_base::sync_with_stdio(false);
	
	
	cin >> x1 >> Y1 >> x2 >> y2 >> vx1 >> vY1 >> vx2 >> vy2;
	

	cout << setprecision(12) << fixed << ternary_search(0.0, (double)INF) << endl;

    return 0;
}
