#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    ll input;
    ll prod;
    ll subprod = 1;
    vector<ll>seq;
    
    while(cin >> input) {
        if(input != -999999) {
            seq.pb(input);
        }

        else {
            prod = seq[0];
            for(int i = 0; i < seq.size(); i++) {
                for(int j = i; j < seq.size(); j++)
                {
                    subprod *= seq[j];
                    if(subprod > prod) prod = subprod;
                }
                subprod = 1;
            }        
            cout << prod << endl;
            prod = 1;
            seq.clear();
        }
    }
    
    
    return 0;
}

