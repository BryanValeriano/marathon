#include <bits/stdc++.h>
using namespace std;

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
const int T = 502;
int mat[T][T];
int aux[4][T][T];
int mov[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
int n,m,l,u,ans;


void read() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            for(int k = 0; k < 4; k++) aux[k][i][j] = mat[i][j];
        }
    }

    for(int k = 0; k < 4; k++) {
        int i = (mov[k][0] > 0? 0: n-1);
        while(i >= 0 && i < n) {
            int j = (mov[k][1] > 0? 0: m-1);
            int ii = i-mov[k][0];
            while(j >= 0 && j < m) {
                int jj = j-mov[k][1];
                if(ii >= 0 && ii < n) aux[k][i][j] = max(aux[k][i][j], aux[k][ii][j]);
                if(jj >= 0 && jj < m) aux[k][i][j] = max(aux[k][i][j], aux[k][i][jj]);
                j += mov[k][1];
            }
            i += mov[k][0];
        }
   }
}

void solve() {
    ans = INF;

    for(int i = 1; i+1 < n; i++) {
        for(int j = 1; j+1 < m; j++) {
            int a = -INF;
            int b = INF;
            for(int k = 0; k < 4; k++) {
                int ii = i - mov[k][0];
                int jj = j - mov[k][1];
                a = max(a, aux[k][ii][jj]);
                b = min(b, aux[k][ii][jj]);
            }
            ans = min(ans,a-b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        read();
        solve();
        cout << ans << endl;
    }
    return 0;
}

