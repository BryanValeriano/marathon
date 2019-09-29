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

const int T = 1e4;
int mat[T][T];
int lastR[T];
int lastC[T];
int n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                mat[i][j] = 1;

        while(k--) {
            int a,b;cin >> a >> b;
            mat[a][b] = 0;
            lastR[b] = a;
            lastC[a] = b;
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            lastR[i] = max(lastR[i], lastR[i-1]);
            for(int j = 1; j <= m; j++) {
                lastC[j] = max(lastC[j], lastC[j-1]);
                if(mat[i][j] == 0) { cout << 0 << " "; continue; }
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - (mat[i-1][j-1] - mat[lastR[i]][lastC[j]]);
                if(tc == 1) cout << mat[i][j] << " ";
                ans += mat[i][j];
            }
            if(tc == 1) cout << endl;
        }

        cout << ans << endl;
    }

    return 0;
}

