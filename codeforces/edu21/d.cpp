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

const int T = 1e5 + 5;
ll v[T];
multiset<ll> a;
multiset<ll> b;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
	ll sumA = 0, sumB = 0;
	cin >> n;	
	b.insert(0);

	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		b.insert(v[i]);
		sumB += v[i];
	}

	for(int i = 0; i <= n; i++) {
		sumA += v[i];
		sumB -= v[i];

		a.insert(v[i]);
		b.erase(b.find(v[i]));

		if(sumA == sumB){ cout << "YES" << endl; return 0; }

		if(sumA > sumB) {
			ll x = sumA - sumB;
			if(!(x&1))
				if(a.count(x/2)) { cout << "YES" << endl; return 0; }
		} else if(sumB > sumA) {
			ll x = sumB - sumA;
			if(!(x&1))
				if(b.count(x/2)) { cout << "YES" << endl; return 0; }
		}
	}

	cout << "NO" << endl;
    
    return 0;
}
