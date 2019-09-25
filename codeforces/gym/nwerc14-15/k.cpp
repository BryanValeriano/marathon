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
 
ll n,s,t;

ll pos[2020];
ll ans[11100100];
	
ll go(ll onde){

	ll sum=0;
	multiset<ll> q;
	
	fr(i,n)
		q.insert(pos[i]);

	while(!q.empty()){

		auto it = q.lower_bound(onde);
		
		//n vazio e n tem na minha frente, volta pro inicio
		if(it==q.end()){
			sum+=s-onde;
			onde=0;
			continue;
		}

		//soma tempo de chegar na mala		
		sum+=(*it)-onde;
		onde=*it;
		q.erase(it);

		//senao atualiza pos e continua
		sum+=t;
		onde=(onde+t)%s;
	}

	return sum;
}

int main(){

	fastio;

	cin >> n >> s >> t;

	fr(i,n)
		cin >> pos[i];

	ms(ans,-1);

	fr(i,n)
		ans[pos[i]]=go(pos[i]);

	set<ll> q;
	fr(i,n)
		q.insert(pos[i]);

	fr(i,s){
		
		if(ans[i]!=-1)
			continue;

		auto it = q.lower_bound(i);
		ll cost=0;
		ll onde = i;

		if(it == q.end()){
			cost+=s-i;
			onde=0;
			it = q.lower_bound(0);
		}
		cost+=(*it)-onde;
		cost+=ans[*it];
		ans[i]=cost;
	}	

	ll mn=1e18;
	ll mx=0;
	ll sum=0;

	fr(i,s){
		mx=max(mx,ans[i]);
		mn=min(mn,ans[i]);
		sum+=ans[i];
	}

	// cout << "######" << endl;
	// fr(i,s)
	// 	cout << ans[i] << endl;
	// cout << "#####"<<endl;

	cout << mn << endl;
	cout << mx << endl;
	ll div = __gcd(sum,s);
	cout << sum/div << "/" << s/div << endl;

}