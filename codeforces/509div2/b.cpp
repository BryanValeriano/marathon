#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,x,y;
    cin >> a >> b >> x >> y;
    
    ll gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;

    cout << min(a/x,b/y) << endl; 
    
    return 0;
}

