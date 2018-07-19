#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair

typedef long long ll;

vector<string> dict;
vector<string> codes;
vector<int> pmt;
int now;
int total;

void backtrack(int casa, int x)
{
    if(x == total)
    {
        int j = 0;
        for(int i = 0; i < codes[casa].size(); i++)
        {
            if(codes[casa][i] == '#') cout << dict[now];
            else
            {
                cout << pmt[j];
                j++;
            }
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        pmt[x] = i;
        backtrack(casa, x + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    string palavra;
    

    while(cin >> n)
    {
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
                if(codes[i][j] == '0' )
                {
                    pmt.pb(0);
                    total++;
                }
            }
            cout << "--" << endl;
            for(int j = 0; j < dict.size(); j++)
            {
                now = j;
                backtrack(i, 0);
            }
            pmt.clear();
            total = 0;
        }

        dict.clear();
        codes.clear();
    } 
    
    return 0;
}

