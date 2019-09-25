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
 
#define gnl cout << '\n'
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pli;
 
const int INF = 0x3f3f3f3f;

ll qtd[500500];
int in[500500];
bool ini[500500];
pii adj[500500];
ll n,m;

int main(){
	scanf("%lld %lld\n", &n, &m);

	char x;
	int y,a;
	frr(i,m){
		//olar;
		scanf("%c", &x);
		scanf("%d", &y);
		scanf("%d\n", &a);
		if(x == 'L'){
			ini[i] = true;
		}
		adj[i].fst = y; in[y]++;	
		adj[i].snd = a; in[a]++;
	}
	//dfs(1,n);

	qtd[1] = n;
	queue<int> fila;

	for(int i = 1; i <= m; i++) 
		if(!in[i]) fila.emplace(i);

	while(!fila.empty()) {
		int v = fila.front();
		fila.pop();
		if(v == 0) continue;

		ll x = qtd[v];
		in[adj[v].fst]--;
		in[adj[v].snd]--;
		if(!in[adj[v].fst]) fila.push(adj[v].fst);
		if(!in[adj[v].snd] and adj[v].fst != adj[v].snd) fila.push(adj[v].snd);

		if(x%2){
			if(adj[v].fst == adj[v].snd){
				qtd[adj[v].fst] += x;
				continue;
			}
			if(ini[v]){
				qtd[adj[v].fst] += (x/2) + 1ll;
				qtd[adj[v].snd] += x/2;
				
			}
			else{
				qtd[adj[v].snd] += (x/2) + 1ll;
				qtd[adj[v].fst] += x/2;
			}
		}
		else{
			if(adj[v].fst == adj[v].snd){
				qtd[adj[v].fst] += x;
				continue;
			}
			qtd[adj[v].fst] += x/2;
			qtd[adj[v].snd] += x/2;
		}
	}

	string s;
	frr(i,m){
		if(qtd[i]&1) ini[i] = !ini[i];
		if(ini[i]) s.pb('L');
		else s.pb('R');
	}
	printf("%s\n", s.c_str());

	return 0;
}