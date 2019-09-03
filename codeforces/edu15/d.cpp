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
 
int main(){
    ios_base::sync_with_stdio(false);
	ll d,k,a,b,t;
	cin >> d >> k >> a >> b >> t;
	ll ini = 0;
	ll foot = 0;
	ll car = 0;
	if(k <= d) {
		car = k*a;
		foot = k*b;
		if(car < foot) ini = car;
		else {
			cout << d*b << endl;
			return 0;
		}
		car = (k*a)+t;
		if(car <= foot) {
			ll vezes = (d-k)/k;
			ll sobra = (d-k) - (vezes * k);
			if(sobra*b <= (sobra*a) + t) sobra = sobra*b;
			else sobra = (sobra*a) + t;
			cout << ini + vezes*car + sobra << endl;
		}
		else cout << ini + (d-k)*b << endl;
	} else cout << min(d*a, d*b) << endl;
    return 0;
}
