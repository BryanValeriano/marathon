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

map<char,ll> a;
map<char,ll> b;
map<char,ll> c;
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n; cin >> n;

	string A,B,C;
	cin >> A >> B >> C;

	ll maxa, maxb, maxc;
	maxa = maxb = maxc = 0;

	for(int i = 0; i < A.size(); i++) a[A[i]]++;
	for(int i = 0; i < B.size(); i++) b[B[i]]++;
	for(int i = 0; i < C.size(); i++) c[C[i]]++;

	ll aa = A.size();
	ll bb = B.size();
	ll cc = C.size();

	for(auto x : a) {
		ll sobra = 0;
		ll tmp = x.se;
        if(n == 1 and tmp+n > aa) tmp--; 
		else tmp = min(tmp+n, aa);
		maxa = max(maxa,tmp);
	}
	
	for(auto x : b) {
		ll sobra = 0;
		ll tmp = x.se;
        if(n == 1 and tmp+n > aa) tmp--; 
		else tmp = min(tmp+n, bb);
		maxb = max(maxb,tmp);
	}

	for(auto x : c) {
		ll sobra = 0;
		ll tmp = x.se;
        if(n == 1 and tmp+n > aa) tmp--; 
		else tmp = min(tmp+n, cc);
		maxc = max(maxc,tmp);
	}


	if(maxa > maxb and maxa > maxc) cout << "Kuro" << endl; 
	else if(maxb > maxa and maxb > maxc) cout << "Shiro" << endl; 
	else if(maxc > maxa and maxc > maxb) cout << "Katie" << endl; 
	else cout << "Draw" << endl;
    
    return 0;
}
