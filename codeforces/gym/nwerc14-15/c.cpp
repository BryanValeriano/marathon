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
 
 int n,d;
 int v[30000];
 int memo[2020][30];

int round(int n){
	if(n%10 < 5)
		return ((n/10)*10);
	else{
		n /=10;
		n++;
		n*=10;
		return n;
	}
}

int dp(int ind,int bar){
	if(ind == n) return 0;
	if(bar == -1) return INF;

	int& pdm = memo[ind][bar];
	if(pdm != -1) return pdm;
	pdm = INF;
	int ans = 0;

	for(int j = ind; j < n;j++){
		ans += v[j];
		pdm = min(pdm,round(ans) + dp(j + 1,bar-1));
	}

	return pdm;
}

int main(){

	fastio;
	ms(memo,-1);
	cin >> n >> d;
	fr(i,n) cin >> v[i];
	cout << dp(0,d) << endl;
	

}