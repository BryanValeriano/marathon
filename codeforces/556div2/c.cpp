#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 5e5 + 5;
int dois;
int um;
bitset<T> crivo;
vector<int> primes;

void pre() {
	for(int i = 2; i < T; i++) {
		if(!crivo[i]) {
			primes.pb(i);
			for(int j = i+i; j < T; j += i) crivo[j] = 1;
		}
	}
}

void rest(int um, int dois)  {
	while(dois) { cout << 2 << " "; dois--; }
	while(um) { cout << 1 << " "; um--; }
}
 
int main() {
    ios_base::sync_with_stdio(false);
	pre();

	int n, tmp; cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp == 1) um++;
		else dois++;
	}

	ll sum = 0;
	int at = 0;

	while((um or dois) and at < primes.size()) {
		int d = 0, u = 0;

		while(at < primes.size() and primes[at] <= sum) at++;
		int nxt = primes[at] - sum;

		if(dois) {
			d = nxt/2;
			d = min(d,dois);
			if(d*2 < nxt) {
				nxt -= d*2;
				if(um >= nxt) u = nxt;
			}
		} 
		else if(um >= nxt) u = nxt;
		else { rest(um, dois); return 0; }

		while(d) { cout << 2 << " "; dois--; d--; sum += 2; }
		while(u) { cout << 1 << " "; um--; u--;  sum += 1; }

		if(sum <= primes[at]) at++;
	}
	cout << endl;

    return 0;
}
