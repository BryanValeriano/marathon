#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int TAM = 1e5+5;
vector <int> mob[TAM];
int peso[TAM];
int n, maior=-1;
bool bem = true;

int pesa(int no){

	if(mob[no].size()==0) return 1;
	
	for(int i=0; i<mob[no].size(); i++){
		peso[no]+=pesa(mob[no][i]);
	}
	peso[no]+=1;
	return peso[no];
}

void dfs(int no){
	
	int pesoAtual=-1;
	for(int i=0; i<mob[no].size(); i++){
		if(pesoAtual==-1) pesoAtual = peso[mob[no][i]];
		else if(pesoAtual!=peso[mob[no][i]]) bem = false;
	}
	for(int i=0; i<mob[no].size(); i++){
		dfs(mob[no][i]);
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n;
	int aux, aux2;
	fori(i, 0, n){
		cin >>aux >>aux2;
		mob[aux2].pb(aux);
	}
	
	memset(peso, 0, sizeof(peso));
	pesa(0);
        //for(int i = 0; i <= n; i++) cout << i << " " << peso[i] << ", ";
        //cout << endl;

	dfs(0);

	if(bem) cout <<"bem" <<endl;
	else cout <<"mal" <<endl;
    
    return 0;
}

