#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll days[n];
    ll sum = 0;
    
    for(ll i = 0; i < n; i++)
    {
        cin >> days[i];
        sum += days[i];
    }
    
    ll total = 0;
    ll cont = 0;

    while(total < ceil(sum/2))
    {
        total += days[cont];
        cont++;
    }
   
    cout << cont << endl;

    return 0;
}

