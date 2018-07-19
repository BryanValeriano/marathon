#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int modulo = 1e8;
int n1,n2,k1,k2;
int cont1 = 0;
int cont2 = 0;
int tam1 = 0;
int tam2 = 0;
int row[200 + 3];
int dp[200 + 3][3];

int vimerum(int pos)
{
    int R = 0;
    int L = 0;
    int aux1, aux2;
    if(pos > n1+n2) return 0;
    if(pos == n1+n2)
    {
        for(int i = 0; i < n1+n2; i++)
            cout << row[i] << " ";
        cout << endl;

        return 1;
    }


    if(cont1 < k1 && tam1 < n1)
    { 
        aux2 = cont2;
        cont2 = 0;
        cont1++;
        tam1++;

        row[pos] = 0;
        R = vimerum(pos + 1)%modulo;

        cont2 = aux2;
        cont1--;
        tam1--;
    }

    if(cont2 < k2 && tam2 < n2)
    { 
        aux1 = cont1;
        cont1 = 0;
        cont2++;
        tam2++;

        row[pos] = 1;
        L = vimerum(pos + 1)%modulo;

        cont1 = aux1;
        cont2--;
        tam2--;
    }
    
    return /*dp[pos][value] = */(R + L)%modulo;
}
	
int main()
{
	int cont = 0;
        int resp = 0;
	cin >> n1 >> n2 >> k1 >> k2;
        memset(row, -1, sizeof row);
        memset(dp, -1, sizeof dp);

        //for(int i = 0 ; i < n1+n2; i++)
        //    cout << dp[i] << " ";
        //cout << endl;
        cout << vimerum(0) << endl;
	
    return 0;
}
