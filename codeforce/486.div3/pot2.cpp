#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    vector<ll>resp;
    ll j = 0;
    for(ll i = 1; i <= 2e9; i *= 2)
        resp.pb(i);

    cout << resp.size() << endl;

    for(int i = 0; i < resp.size(); i ++)
        cout << resp[i] << " ";

    cout << endl;
    
    return 0;
}

