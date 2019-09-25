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

struct point{

	ll x,y;
	point(){}
	point(ll a, ll b){x=a,y=b;}

	point operator-(point p){return point(x-p.x,y-p.y);}
	ll operator^(point p){return x*p.y-y*p.x;}

};

vector<point> v;

int check(point a, point b){
	int cnt=0; 
	for(auto p : v){
		if( ((p-a)^(p-b))==0 )
			cnt++;
	}
	return cnt;
}
 
int main(){

	fastio;

	int n; cin >> n;

	if(n==1){
		cout << "possible" << endl;
		return 0;
	}

	ll p;
	cin >> p;

	ll desired = (p*n + 99)/100;
	//dbg(desired);


	fr(i,n){
		point p;
		cin >> p.x >> p.y;
		v.pb(p);
	}
	//auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	//mt19937 mt_rand(seed);

	std::default_random_engine generator;
  	std::uniform_int_distribution<int> distribution(0,n-1);

	bool flag = false;
	fr(k,4000){
		int i = distribution(generator)%n;
		int j = distribution(generator)%n;
		if(i==j)
			i=(i+1)%n;
		if(check(v[i],v[j])>=desired)
			flag=true;
	}

	cout << (flag ? "possible" : "impossible") << endl;

}