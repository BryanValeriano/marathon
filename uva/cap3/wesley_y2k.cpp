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

const int POSTS = 12;
ll qtd[15];
ll soma=0, d, s;

bool verifica(){
    for(int i=4; i<POSTS; i++){
        if((qtd[i]+qtd[i-1]+qtd[i-2]+qtd[i-3]+qtd[i-4])>=0) 
            return false;
    }
    return true;
}

void imprime(){
    for(int i=0; i<POSTS; i++) cout <<qtd[i] <<' ';
    cout <<endl;
}

ll bt(int pos){
    ll total = -1;
    if(pos==POSTS){
        if(verifica()){
            soma=0;
            for(int i=0; i<POSTS; i++) soma+=qtd[i];
            return soma;
        }
        return -1;
    }

    qtd[pos] = s;
    total = max(total, bt(pos+1));
    qtd[pos] = d;
    total = max(total,bt(pos+1));

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);


    while(cin >>s){
        cin >>d;

        cout <<bt(0);
    }

    return 0;
}
