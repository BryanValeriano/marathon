#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define eb emplace_back
#define loop(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define len(a) (int)(a).size()
#define allv(a) (a).begin(),(a).end()
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double err = 1e-9;
const int mod = 1e9+7;
const int N = 1e5+10;

int fr[1001];
int np[21*21];
int nq[21*21];
int ar[21][21];

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);
	
	int n,x;
	cin>>n;
	loop(i,0,n*n)cin>>x,fr[x]++;
	int p = 0,p2 = 0;
	int cc = 0;
	int v = -1;
	loop(i,1,1001){
		while(fr[i]>=4 and p<(n/2)*(n/2)){
			fr[i]-=4;	
			np[p++]=i;
		}
		while(fr[i]>=2){
			fr[i]-=2;
			nq[p2++]=i;
		}
		if(fr[i]>0)cc+=fr[i],v=i;
	}
	//cout<<"A\n";
	if(n%2==0 and (cc!=0 or p2!=0)){cout<<"NO\n";return 0;}
	if(n%2!=0 and (cc!=1 or p<(n/2)*(n/2))){cout<<"NO\n";return 0;}
	cout<<"YES\n";
	int c = 0;	
	loop(i,0,n/2)loop(j,0,n/2){
		ar[i][j] = ar[n-i-1][n-j-1] = ar[i][n-1-j] = ar[n-i-1][j] = np[c++]; 	
	}
	int c2 = 0;
	bool f = 0;
	if(n%2==1){
		loop(j,0,n/2){ar[n/2][j] = ar[n/2][n-j-1] = nq[c2++];}//c2<p2?nq[c2++]:(f?np[c++]:np[c]);if(c2>=p2)f!=f;}
		loop(i,0,n/2){ar[i][n/2] = ar[n-i-1][n/2] = nq[c2++];}//c2<p2?nq[c2++]:(f?np[c++]:np[c]);if(c2>=p2)f!=f;}
		ar[n/2][n/2] = v;
	}
	loop(i,0,n){
		loop(j,0,n)cout<<ar[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
