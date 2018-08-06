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
    int n, aux1 = 0, aux2 = 0; cin >> n;
    vector<int>row;
    cin >> aux1; aux2 = aux1;
    for(int i = 1; i < n; i++)
    {
        cin >> aux1;
        if(aux1 <= aux2) row.pb(aux2);
        aux2 = aux1;
    }
    row.pb(aux2);
    int tam = row.size();
    cout << tam << endl;
    for(int i = 0; i < tam; i++)
    {
        cout << row[i];
        if(i + 1 < tam) cout << " "; 
    } 
    cout << endl;   
    
    
    return 0;
}

