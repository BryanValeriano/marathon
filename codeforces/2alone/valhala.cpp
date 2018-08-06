#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int n, q;

int main(){
    ios_base::sync_with_stdio(false);
    
    vector<ll>strenghts;
    vector<ll>base;
    ll arrows[200005];


    cin >> n >> q;
    ll tmp, rest;
    int j;

    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        strenghts.pb(tmp);
        base.pb(tmp);
    }
    for(int i = 0; i < q; i++)
        cin >> arrows[i];

    for(int i = 0; i < q; i++)
    {
        rest = arrows[i];
        j = 0;
        while(rest != 0 && strenghts.size() > 0)
        {
            if(rest - strenghts[j] >= 0)
            {
                rest = rest - strenghts[j];
                strenghts.erase(strenghts.begin() + j);
            }
            else
            {
                strenghts[j] -= rest;
                rest = 0;
            }
        }
        
        if(strenghts.size() > 0) cout << strenghts.size() << endl;
        else
        {
            strenghts = base;
            cout << strenghts.size() << endl;
        }
    }
    
    return 0;
}

