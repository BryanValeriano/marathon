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
    ios::sync_with_stdio(false);
    int tc, n, aux; cin >> tc;
    while(tc--) {
        cin >> n;
        int pos = 0;
        int neg = 0;
        int nulo = 0;
        for(int i = 0; i < n; i++) {
            cin >> aux;
            if(aux > 0) pos++;
            else if(aux < 0) neg++;
            else nulo++;
        }
        if(pos < neg) swap(pos,neg);
        pos += nulo;
        if(neg == 0) cout << pos << " " << pos << endl;
        else cout << pos << " " << neg << endl;
    }
    return 0;
}

