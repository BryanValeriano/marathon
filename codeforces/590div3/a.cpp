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
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll x = 0;
        ll sum = 0;
        ll t = n;
        while(n--) cin >> x, sum += x;
        n = sum/t;
        if(sum%t) n++;
        cout << n << endl;
    }
    return 0;
}

