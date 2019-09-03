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
    ll n; cin >> n;
    ll g = 0;
    ll h = 0;
    ll x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        g = max(g,x);
    }

    for(int i = 0; i < n; i++) cin >> x;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> x, h += x;
    
    cout << n*g + h << endl;

    return 0;
}

