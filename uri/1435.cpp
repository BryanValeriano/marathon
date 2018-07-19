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
    cin >> n;
    while(n != 0)
    {
        double m = double(n);
        int tela[n][n];
        if(n%2 != 0)
        {
            int meio = floor(m/2);
            cout << meio << endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(abs(max(meio - i, meio - j) < 0)) cout << 1;
                    else cout << abs(max(meio - i, meio - j));
                    if(j+1 < n) cout << " ";
                }
                cout << endl;
            }
        }
        cin >> n;
        if(n != 0) cout << endl;
    }
            
    
    
    return 0;
}

