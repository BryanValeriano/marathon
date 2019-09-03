#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
vector< pair <int, int> > V;
int cont = 0;

void maxcomb(int x, int y, int a, int b, int inicio)
{
    int j = inicio;
    for(int i = b; i <= y; i++)
    {
        if(j > i)
        {
            cont++;
            V.pb(mk(j,i));
        }
    }
    if(j < x) return maxcomb(x, y, a, b, inicio + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int x, y, a, b;

    cin >> x >> y >> a >> b;

    int inicio = a; 

    maxcomb(x, y, a, b, inicio);
   
    cout << cont << endl;
    for(int i = 0; i < cont; i++)
    {
        cout << V[i].first << " " << V[i].second << endl;
    }
    return 0;
}

