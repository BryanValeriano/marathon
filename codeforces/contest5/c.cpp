#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main()
{
    ll n;
    cin >> n;

    map<ll,ll> table;
    ll tmp;
    vector<ll> nums;
    ll aux;
    
    for(ll i = 0; i < n; i++)
    {
        cin >> tmp;
        nums.pb(tmp);
        if(table.count(tmp)) table[tmp] += 1;
        else table.insert(mk(tmp, 1));
    }

    ll i = 0;
    int j = 0;
    ll direita, esquerda;
    int sinal = 0;
    
    map<ll,ll>::iterator it=table.begin();

    while(it->second < 2)
    {
        if(it != table.end())it++;
    }
    while(it->second >= 2 && it != table.end())
    {
        while(sinal < 2)
        {
            if(nums[j] == it->first && sinal == 0)
            {
                esquerda = j;
                sinal++;
            }
            else if(nums[j] == it->first && sinal == 1)
            {
                direita = j;
                sinal++;
                j = 0;
                break;
            }
            j++;
        }
        sinal = 0;
        nums.erase(nums.begin()+esquerda);
        nums[direita - 1] *= 2;
        table[nums[direita - 1]] += 1;
        table[it->first] -= 2;
        if(table[it->first] < 2)
        {
            it = table.begin();
            while(it->second < 2 && it != table.end()) it++;
        }
    }

    cout << nums.size() << endl;

    for(ll k = 0; k < nums.size(); k++)
    {
        cout << nums[k] << " ";
    }
    cout << endl;
        
    return 0;
}

