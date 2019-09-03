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

const int T = 1e5 + 10;
int n,q;
int v[30][T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {

        memset(v, 0, sizeof v);

        cin >> n >> q;
        char x;

        for(int i = 0; i < n; i++) {
            cin >> x;
            v[x-'A'][i+1]++;
        }

        for(int i = 0; i < 26; i++) {
            for(int j = 1; j <= n; j++) {
                v[i][j] += v[i][j-1];
            }
        }
        

        int l,r;
        int ans = 0;

        while(q--) {
            cin >> l >> r;
            int impar = 0;

            for(int i = 0; i < 26; i++)  
                if((v[i][r] - v[i][l-1]) & 1) impar++;
            
            if(impar <= 1) ans++;
        }
        cout << "Case #" << ++cont << ": " << ans << endl;
    }
    return 0;
}

