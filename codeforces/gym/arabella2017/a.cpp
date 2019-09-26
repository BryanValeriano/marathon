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

const int T = 2e5 + 3;

int n;
string s;
int v[T];
int imp[T];
int par[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> s;
        n++;
        s = "0" + s;

        v[0] = (s[0] == '1');

        for(int i = 1; i < n; i++) v[i] = (v[i-1] + (s[i] == '1'));
        imp[n] = par[n] = 0;

        for(int i = n-1; i >= 0; i--) {
            imp[i] = imp[i+1] + (v[i]&1);
            par[i] = par[i+1] + (!(v[i]&1));
        }

        //for(int i = 0; i < n; i++) cout << v[i] << " ";
        //cout << endl;
        //for(int i = 0; i < n; i++) cout << par[i] << " ";
        //cout << endl;
        //for(int i = 0; i < n; i++) cout << imp[i] << " ";
        //cout << endl;

        ll ans = 0;
        for(int i = 0; i < n-3; i++) {
            if(v[i]&1) ans += par[i+3];
            else ans += imp[i+3];
        }

        int z = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') z++;
            else {
                if(z >= 2) ans -= z-1;
                z = 0;
            }
        }

        z = 0;
        for(int i = n-1; i >= 1; i--) {
            if(s[i] == '0') z++;
            else {
                if(z >= 2) ans -= z-1;
                z = 0;
            }
        }   

        cout << ans << endl;
    }
    
    return 0;
}

