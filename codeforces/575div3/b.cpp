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

const int T = 2e5 + 2;
int v[T];
int n,k;

int main() {
    ios::sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        cin >> n >> k;
        int imp = 0;
        for(int i = 0; i < n; i++) { cin >> v[i]; if(v[i]&1) imp++; }
        int x = imp - (k-1);

        if(k == 1 and (imp&1)) {
            cout << "YES" << endl;
            cout << n << endl;
            continue;
        }

        if(x > 0 and (x&1)) {
            cout << "YES" << endl;
            int ok = 0;
            bool f = 0;
            bool um = 0;
            int pqp = 0;
            for(int i = 0; i < n; i++) {
                if(v[i]&1) {
                    x--;
                    if(f and pqp < k-1) cout << i+1 << " ", pqp++;
                    if(x == 0) { 
                        cout << i+1 << " ";
                        f = 1;
                        pqp++;
                    } 
                }
            }
            cout << n << endl;
        } else cout << "NO" << endl;

    }

    return 0;
}

