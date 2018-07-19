#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int S, P;
    int sinal = 0;
    cin >> S >> P;
    vector<char>row;
    char tmp;
    for(int i = 0; i < S; i++)
    {
        cin >> tmp;
        row.pb(tmp);
    }

    for(int i = 0; i < row.size() - P; i++)
        if(row[i] == row[i + P])
            if(row[i] == '.' || row[i + P] == '.')
                continue;
            else
            {
                sinal ++;
            }

   if(sinal != row.size() - P)
   {
        for(int i = 0; i < row.size(); i++)
            if(row[i] == '.' && i < (row.size() - P) && row[i+P] == '.') 
            {
                cout << 0;
                row[i+P] = '1';
            }
            else if(row[i] == '.' && i < (row.size() - P) && row[i+P] != '.') cout << (1 - (row[i+P] - '0'));
            else if(row[i] == '.') cout << 0;
            else cout << row[i];

        cout << end;
    }
    else cout << "No" << endl;
    return 0;
}

