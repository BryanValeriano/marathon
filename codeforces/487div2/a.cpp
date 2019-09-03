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
    string row;
    getline(cin, row);
    if(row.size() >= 3)
        for(int i = 2; i < row.size(); i++)
            if(row[i] != '.' && row[i-1] != '.' && row[i-2] != '.')
                if(row[i] != row[i -1] && row[i] != row[i -2])
                    if(row[i - 1] != row [i - 2])
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
    cout << "No" << endl;

    
    return 0;
}

