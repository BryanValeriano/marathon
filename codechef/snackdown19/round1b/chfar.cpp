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
        int n, k; cin >> n >> k;
        int cont = 0;
        int aux;
        for(int i = 0; i < n; i++) {
            cin >> aux;
            if(aux != 1) cont++;
        }
        cout << (cont > k? "NO" : "YES") << endl;
    }
    return 0;
}

