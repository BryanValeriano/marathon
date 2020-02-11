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
        int odd = 0, even = 0;

        while(n--) {
            int x; cin >> x;
            if(x&1) odd++;
            else even++;
        }

        cout << ((odd&1) or (odd and even)? "YES" : "NO") << endl;
    }
    return 0;
}

