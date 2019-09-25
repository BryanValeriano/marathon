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
 
int n;
long double p,s,v;

long double f(long double c){

	long double left = n*pow(log2(n),c*sqrt(2));
	left/=p*1e9;

	long double right = s*(1.0 + 1.0/c);
	right/=v;

	return left+right;

}

int main(){

	fastio;

	cin >> n >> p >> s >> v;

	cout << setprecision(10) << fixed;

	long double ini = 0.000001;
	long double fim = 1e10;

	fr(i,4000){
		long double delta = (fim-ini)/3.0;
		long double a = ini+delta;
		long double b = fim-delta;
		if(f(a)>f(b))
			ini=a;
		else
			fim=b;
	}


	cout << f(ini) << " " << ini << endl;

}