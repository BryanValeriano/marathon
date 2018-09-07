#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int tam, turn;
    cin >> tam >> turn;
    int resp = 0;
    int espatula = turn + 1 + turn;
    vector<int>track;
    int fim = turn + turn;
    int meio;
    int auxfim = min(tam-1, fim);
    if(auxfim >= tam-1) {
        cout << 1 << endl << 1 << endl; return 0;
    }
    while(auxfim < tam-1) {
        auxfim = min(tam-1, fim);
        meio = fim - turn;
        fim = espatula + fim; 
        resp++;
        track.pb(min(meio+1, tam-1));
    }

    cout << resp << endl;    
    for(int i = 0; i < track.size(); i++) 
        cout << track[i] << " ";
    cout << endl;
    return 0;
}

