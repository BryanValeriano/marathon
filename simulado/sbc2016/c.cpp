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
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b || a == c || b == c || a == b + c || b == a + c || c == a + b)
        cout << "S";
    else cout << "N"; 
    cout << endl;
    
    return 0;
}

