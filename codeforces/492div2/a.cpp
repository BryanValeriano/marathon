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
    ll n;
    int cont = 0;
    cin >> n;
    while(n > 0)
    {
        if(n - 100 >= 0)
            n = n - 100;
        else if(n - 20 >= 0)
            n = n - 20;
        else if(n - 10 >= 0)
            n = n - 10;
        else if(n - 5 >= 0)
            n = n - 5;
        else if(n - 1 >= 0)
            n = n - 1;
        cont++;
    }
    cout << cont << endl;

    
    return 0;
}
