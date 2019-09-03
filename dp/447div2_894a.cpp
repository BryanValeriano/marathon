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
    vector<int>row;
    vector<int>flag;
    char aux;
    int cont = 0, j = 0;
    while(cin >> aux) {
        if(aux == 'Q') cont++;
        if(aux == 'A') flag.pb(j);
        row.pb(cont);
        j++;
    } 
    int resp = 0;
    for(int i = 0; i < flag.size(); i++)
        resp += row[flag[i]] * (row[row.size() - 1] - row[flag[i]]); 

    cout << resp << endl;
    
    return 0;
}

