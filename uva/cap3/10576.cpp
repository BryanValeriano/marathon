#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
ll n, m, maxx, sum;
ll meses[12];

ll soma()
{
    ll aux = 0;
    for(int i = 0; i < 12; i++)
    {
        aux += meses[i];
        //cout << meses[i] << " ";
    }
    //cout << endl;
    return aux;
}

bool checa()
{
    ll aux = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = i; j <= (i + 4); j++)
        {
            aux += meses[j];
        }
        if(aux >= 0) return false;
        aux = 0;
    }
    return true;
}



void backtrack(int x)
{
    sum = soma(); 
    if(x == 12)
    {
        if(checa())
            if(sum > maxx) maxx = sum;
        return;
    }

    meses[x] = n;
    backtrack(x + 1);
    meses[x] = m;
    backtrack(x + 1);
}
 
int main(){
    ios_base::sync_with_stdio(false);

    while(cin >> n)
    {
        cin >> m;
        m = m * -1;
        sum = 0;
        maxx = 0;
        memset(meses, 0, sizeof(meses));
        backtrack(0);
        if(maxx > 0) cout << maxx << endl;
        else cout << "Deficit" << endl;
    }
    
    return 0;
}

