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
    ll x; cin >> x;

    for(ll i = 1; i*i <= x; i++) 
        if(i*i == x or i*i + (i-1)*(i-1) == x) { cout << "YES" << endl; return 0; }
    
    cout << "NO" << endl;
    
    return 0;
}

