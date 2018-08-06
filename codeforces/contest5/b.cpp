#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;
    string line;

    cin >> line;
    ll cont = 0;
    int lastA = 0;
    int lastB = 0;

    if(line[0] != '*' && a > b)
    {
        cont++;
        a--;
        lastA = 1;
    }

    else if(line[0] != '*' && a < b)
    {
        cont++;
        b--;
        lastB = 1;
    }
    for(int i = 1; i < n; i++)
    {
        if(line[i] != '*' && lastA == 0 && lastB == 0 && a > b)
        {
            cont++;
            a--;
            lastA = 1;
        }
        else if(line[i] != '*' && lastA == 0 && lastB == 0 && a < b)
        {
            cont++;
            b--;
            lastB = 1;
        }
        else if(line[i] != '*' && lastA == 0 && a > 0)
        {
            cont++;
            a--;
            lastA = 1;
            lastB = 0;
        }
        else if(line[i] != '*' && lastB == 0 && b > 0)
        {
            cont++;
            b--;
            lastB = 1;
            lastA = 0;
        }
        else
        {
            lastA = 0;
            lastB = 0;
        }

    }

    cout << cont << endl;
        
    return 0;
}

