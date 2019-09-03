#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int n, q;
vector<ll>strenghts;

ll bisec(ll num)
{
    int i = 0;
    int f = strenghts.size();
    int m;

    while(f - i > 1)
    {
        m = (i + f) / 2;

        if(strenghts[m] >= num) f = m;
        else i = m;
    }

    //cout << "Teste: " << endl << "arrows :" << num << endl << "Strenght foun: " << strenghts[m] << endl;

    return m;
}

void atualiza(ll rest)
{
    for(int i = 0; i < strenghts.size(); i++)
        strenghts[i] -= rest;
}


int main(){
    ios_base::sync_with_stdio(false);
    
    vector<ll>base;
    ll arrows[200005];


    cin >> n >> q;
    ll tmp, rest;
    int j, pos;
    
    cin >> tmp;
    strenghts.pb(tmp);
    base.pb(tmp);
    
    if(n > 1)
        for(int i = 1; i < n; i++)
        {
            cin >> tmp;
            strenghts.pb(tmp);
            strenghts[i] += strenghts[i - 1];
            base.pb(strenghts[i]);
        }

    for(int i = 0; i < q; i++)
        cin >> arrows[i];

    for(int i = 0; i < q; i++)
    {
        rest = arrows[i];
        pos = bisec(rest);
        if(pos == 1 && strenghts[0] - rest >= 0) pos = 0; 
        if(pos != strenghts.size() - 1 || strenghts[strenghts.size() - 1] - rest > 0)
        {
            if(strenghts[pos] - rest > 0)
                strenghts.erase(strenghts.begin(), strenghts.begin() + pos);
            else
                strenghts.erase(strenghts.begin(), strenghts.begin() + pos + 1);
        
            atualiza(rest);
        }
        else strenghts = base;
        
        cout << strenghts.size() << endl;
    }

    return 0;
}

