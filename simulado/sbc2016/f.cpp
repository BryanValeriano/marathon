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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lim = c/2;
    for(int i = a; i <= lim; i += a) {
        if(c%i == 0 && i%b != 0 && d%i != 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}

