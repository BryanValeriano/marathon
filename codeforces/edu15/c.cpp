#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define int long long

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

int best;
vector<int> cit;
vector<int> tow;
 
int32_t main(){
    ios_base::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m;	
	for(int i = 0; i < n; i++) {
		cin >> x;
		cit.pb(x);
	}

	for(int i = 0; i < m; i++) {
		cin >> x;
		tow.pb(x);
	}
	
	for(int i = 0; i < n; i++) { 
		int up = lower_bound(tow.begin(), tow.end(), cit[i]) - tow.begin();
		int lo = INF;
		if(up > 0) {
			lo = up - 1;
			lo = abs(tow[lo] - cit[i]);
		}
		if(up >= tow.size()) up = INF;
		else up = abs(tow[up] - cit[i]);

		best = max(best, min(up,lo));
	}
   
	cout << best << endl;
    return 0;
}
