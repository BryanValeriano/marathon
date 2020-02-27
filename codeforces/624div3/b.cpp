#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 110;

int a[T];
bool ok[T];
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {

        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ok[i] = 0;
        }

        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            x--;
            ok[x] = 1;
        }

        int p = n;

        for(int i = 0; i < n; i++) {

            int maxi = 0;
            int pos = 0;

            for(int j = 0; j < p; j++) {
                if(a[j] > maxi) {
                    maxi = a[j];
                    pos = j;
                }
            }

            int np = pos;

            for(int j = pos; j < p-1; j++) {
                if(ok[j]) swap(a[j], a[j+1]);
                else break;
                np = j+1;
            }

            p = np;
        }

        bool f = 0;
        //cout << a[0] << " ";
        for(int i = 1; i < n; i++) {
            //cout << a[i] << " ";
            if(a[i] < a[i-1]) f = 1;
        }
        //cout << endl;

        cout << (f? "NO" : "YES") << endl;
    }


    return 0;
}

