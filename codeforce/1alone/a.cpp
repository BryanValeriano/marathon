#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    double k, n, s, p;
    cin >> k >> n >> s >> p;

    float FporPessoa = ceil(n/s);
    FporPessoa *= k;

    ll pacotes = ceil(FporPessoa/p);
    
    cout << pacotes << endl;

    //cout << fporPessoa << endl;
    
    
    return 0;
}

