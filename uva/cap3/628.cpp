#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair

typedef long long ll;

vector<string> dict;
vector<string> codes;
vector<int> pmt;
int cont;

int permute()
{
    cont ++;
    int aux = cont;
    zero();

    for(int i = pmt.size(); i <= 0; i--)
    {
           
    

}

void zero()
{
    for(int i = 0; i < pmt.size(); i++)
    {
        pmt[i] = 0;
    }
}

void backtrack(int casa)
{
    int aux;
    do         
    {
        for(int i = 0; i < dict.size(); i++)
        {
            aux = 0;
            for(int k = 0; k < codes[casa].size(); k++)
            {
                
                if(codes[casa][k] == '#')
                {
                    cout << dict[i];
                }
                else
                {
                    cout << pmt[aux];
                    aux++;
                }
            }
            cout << endl;
        }
    } while(permute());
    cont = 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    string palavra;
    

    while(cin >> n)
    {
        cont = 0;
        while(n--)
        {
            cin >> palavra;
            dict.pb(palavra);
        }
        
        cin >> m;

        while(m--)
        {
            cin >> palavra;
            codes.pb(palavra);
        }
        
        for(int i = 0; i < codes.size(); i++)
        {
            for(int j = 0; j < codes[i].size(); j++)
            {
                if(codes[i][j] == '0' ) pmt.pb(0);
            }
            cout << "--" << endl;
            backtrack(i);
            pmt.clear();
        }

        dict.clear();
        codes.clear();
    } 
    
    return 0;
}

