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
    ll n;
    cin >> n;
    if(n&1) cout << 0 << endl;
    else cout << setprecision(10) << pow(2LL,n/2LL) << endl; 
    return 0;
}

