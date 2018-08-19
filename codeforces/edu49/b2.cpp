#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	ll start;
	if(n&1) start = (ll(pow(n,2))>>1)+1;
	else start = ll(pow(n,2))>>1;
	while(q--) {
		ll lin, col;
		cin >> lin >> col;
		ll casa = n*(lin-1) + col;
		ll resp;
		if((lin+col)&1) {
			if(casa&1)
				resp = (casa>>1)+1+start;
			else 
				resp = (casa>>1)+start;
			cout << resp << endl;
		} else {
			if(casa&1)
				resp = (casa>>1)+1;
			else 
					resp = (casa>>1);
			cout << resp << endl;
		}
	}
    return 0;
}

