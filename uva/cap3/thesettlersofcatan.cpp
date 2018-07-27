#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define for_(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
vector <int> no[27]; 
int cont=0;

void procuraMaior(int i, set <int> percorridoAnt){
    set <int> percorrido = percorridoAnt;

    for(int j=0; j<no[i].size(); j++){
	if(!percorrido.count(no[i][j])){
	    percorrido.insert(i);
	    procuraMaior(no[i][j], percorrido);
	}
    }
    
    if(cont<percorrido.size()) cont=percorrido.size();
}

int main(){
    ios_base::sync_with_stdio(false);

    int	a, b;
    cin >>a >>b;
    
    while(a!=0 && b!=0){

	int x, y;
	for(int i=0; i<b; i++){
	    cin >>x >>y;
	    no[x].pb(y);
	    no[y].pb(x);
	}
     
	set <int> percorrido;
	for(int i=0; i<25; i++){
	    procuraMaior(i, percorrido);
	}
	
	cout <<cont <<endl;
	cin >>a >>b;
    }
    return 0;
}
