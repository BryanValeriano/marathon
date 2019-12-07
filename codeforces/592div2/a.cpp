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
    int tc;
    int a,b,c,d,k;
    cin >> tc;
    while(tc--) {
        cin >> a >> b >> c >> d >> k;
        bool ok = 1;
        for(int i = 0; i <= k; i++) {
            int j = k-i;
            if(i*c >= a and j*d >= b) {
                cout << i << " " << j << endl;
                ok = 0;
                break;
            }
        }
        if(ok) cout << -1 << endl;
    }
    return 0;
}

