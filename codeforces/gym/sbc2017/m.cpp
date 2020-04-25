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
    int a, b, c, soma;
    cin >> a >> b >> c;
    soma = (a + c)*2;
    soma = min((a*4 + b*2), soma);
    soma = min((c*4 + b*2), soma);
    cout << soma << endl;
    
    
    return 0;
}

