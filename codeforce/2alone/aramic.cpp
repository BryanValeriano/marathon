#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string palavra;
    set<string> qtd;

    for(int i = 0; i < n; i++)
    {
        cin >> palavra;           
        sort(palavra.begin(), palavra.end());
        
        if(palavra.size() > 1)
            for(int j = 1; j <= palavra.size(); j++)
                if(palavra[j-1] == palavra[j])
                {
                    palavra.erase(palavra.begin() + j);
                    --j;
                }
            
        qtd.insert(palavra);
    } 
   
    
    cout << qtd.size() << endl;
    /*
    for(set<string>::iterator it = qtd.begin(); it != qtd.end(); ++it)
        cout << *it << " ";
    cout << endl;
    */

    return 0;
}

