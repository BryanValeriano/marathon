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
    int n;
    int cont = 0;
    cin >> n;
    int row[n]; 
    cin >> row[0]; cin >> row[1];
    if(row[0] == 0) cont++;
    if(row[1] == 0) cont++;
    else if(row[1] != 3 && row[1] == row[0]) cont++;
    for(int i = 2; i < n; i++)
    {
        cin >> row[i];
        if(row[i] == 0) cont++;
        else if(row[i] == 1 || row[i] == 2)
        {
            if(row[i] == row[i - 1]) cont++;
            else if(row[i - 1] == 3 && row[i - 2] != row[i] && row[i - 2] != 3) cont++;    
        }
    }
    cout << cont << endl;
   
    return 0;
}

