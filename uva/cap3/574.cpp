#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
ll T, N, sum;
vector<int> lista;
vector<int> track;
set<string> memo;
string aux;

void backtrack(int x)
{
    if(sum == T)
    {
        aux = "";

        for(int j = 0; j < track.size(); j++)
        {
            aux += to_string(track[j]);
            if(j + 1 < track.size()) aux += "+";
        }
        if(memo.count(aux) == 0)
        {
            cout << aux << endl;
            memo.insert(aux);
        }
        return;
    }
    
    for(int i = x; i < lista.size(); i++)
    {
        if(sum + lista[i] <= T)
        {
            sum += lista[i];
            track.pb(lista[i]);
            backtrack(i + 1);
            sum -= lista[i];
            track.pop_back();
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> T >> N;
    ll aux;

    while(T && N)
    {
        for(int i = 0; i < N; i++)
        {   cin >> aux;
            lista.pb(aux);
        }
        cout << "Sums of " << T << ":" << endl;
        sum = 0;
        backtrack(0);
        if(memo.size() == 0) cout << "NONE" << endl;
        memo.clear();
        lista.clear();
        track.clear();

        cin >> T >> N;
    }
    
    return 0;
}

