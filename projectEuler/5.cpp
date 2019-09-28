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

    ll ans = 1;
    int ok; cin >> ok;
    for(ll i = 2; i < ok; i++) 
        ans = (ans*i)/__gcd(ans,i);
    cout << ans << endl; 
    return 0;
}

