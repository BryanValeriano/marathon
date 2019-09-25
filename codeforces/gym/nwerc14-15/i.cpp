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

ll n,l;
ll dist[20][20];

int main(){

	fastio;

	cin >> n >> l; 

	int base = (1<<n)-1;

	vector<int> esquerda;

	fr(i,1<<n){
		if(__builtin_popcount(i)==9){
			esquerda.pb(base);
		}
	}

	//dbg(esquerda.size());


	fr(i,n){
		fr(j,n){
			cin >> dist[i][j];
			dist[j][i]=dist[i][j];
		}		//meu paopau de quejo7
	}

	if(n<=10){
		vi perm={};
		fr(i,n)
			perm.pb(i);
		do{
			ll ans = 0;
			for(int i=1;i<n;i++)
				ans+=dist[perm[i]][perm[i-1]];
			ans+=dist[perm[n-1]][perm[0]];
			if(ans==l){
				cout << "possible" << endl;
				return 0;
			}
		}while(next_permutation(all(perm)));
		cout << "impossible" << endl;
		return 0;
	}


}