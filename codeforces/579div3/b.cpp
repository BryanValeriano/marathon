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
        map<int,int> qtd;

        for(int i = 0; i < 4*n; i++) {
            int x; cin >> x;
            qtd[x]++;
        }

        int need = -1;
        bool f = 1;

        while(qtd.size() > 1) {
            ii big = *qtd.rbegin();
            ii small = *qtd.begin();

            if(need == -1) need = big.fi * small.fi;
            if(big.fi * small.fi != need) f = 0;
            if(big.se != small.se or (big.se%2)) f = 0;
            
            qtd.erase(big.fi);
            qtd.erase(small.fi);
        }

        if(qtd.size() == 1) {
            ii at = *qtd.begin();

            if(need == -1) need = at.fi * at.fi;
            if(at.fi * at.fi != need) f = 0;
            if(at.se % 4) f = 0;

        }

        cout << (f? "YES" : "NO") << endl;

    }

    return 0;
}

