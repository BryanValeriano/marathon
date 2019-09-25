#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
map<string,int> bag;
map<string,int> bag2;
 
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		bag[x]++;
	}

	for(int i = 0; i < n; i++) {
		string x; cin >> x;
		bag2[x]++;
	}

	ll ans = 0;

	for(auto ok : bag) {
		int um = ok.snd;
		int dois = bag2[ok.fst];
		ans += min(um,dois);
	}

	cout << ans << endl;
	fastio;
}