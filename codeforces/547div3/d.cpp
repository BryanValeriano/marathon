#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5;

vector<int> a[30];
vector<int> b[30];

bool visa[T];
bool visb[T];
vector<pair<int,int> >ans;
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	char x;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x != '?') a[x-97].pb(i);
		else a[26].pb(i);
	}
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x != '?') b[x-97].pb(i);
		else b[26].pb(i);
	}
	
	for(int i = 0; i <= 25; i++) {
		for(int j = 0; j < min(a[i].size(), b[i].size()); j++) {
			 ans.eb(a[i][j], b[i][j]);
			 visa[a[i][j]] = true;
			 visb[b[i][j]] = true;
		}
	}
	
	int iter = 0;
	for(int i = 0; i <= 25; i++) {
		if(iter >= a[26].size()) break;
		for(int j = 0; j < b[i].size(); j++) {
			if(iter >= a[26].size()) break;
			if(visa[a[26][iter]] == false and visb[b[i][j]] == false) {
				visa[a[26][iter]] = true;
				visb[b[i][j]] = true;
				ans.eb(a[26][iter], b[i][j]);
				iter++;
			}
		}
	}
			
	iter = 0;
	for(int i = 0; i <= 25; i++) {
		if(iter >= b[26].size()) break;
		for(int j = 0; j < a[i].size(); j++) {
			if(iter >= b[26].size()) break;
			if(visb[b[26][iter]] == false and visa[a[i][j]] == false) {
				visb[b[26][iter]] = true;
				visa[a[i][j]] = true;
				ans.eb(a[i][j], b[26][iter]);
				iter++;
			}
		}
	}
	vector<int> resta;
	vector<int> restb;
	for(int i = 0; i < a[26].size(); i++) 
		if(visa[a[26][i]] == false) resta.pb(a[26][i]);

	for(int i = 0; i < b[26].size(); i++) 
		if(visb[b[26][i]] == false) restb.pb(b[26][i]);

	for(int i = 0; i < min(resta.size(), restb.size()); i++)
		ans.eb(resta[i],restb[i]);

	cout << ans.size() << endl;
	for(auto z : ans) cout << z.fi << " " << z.se << endl;

	return 0;
}
