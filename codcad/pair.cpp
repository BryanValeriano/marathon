#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    vector < pair<string, int> > alunos;
    
    string nome;
    int prova;

    for(int i = 0; i < 10; i++)
    {
        cin >> nome >> prova;
        alunos[i].pb(mk(nome, prova));
    }
   
    for(int i = 0; i < 10; i++)
    {
        cout<<alunos[i];
    }
    
    return 0;
}

