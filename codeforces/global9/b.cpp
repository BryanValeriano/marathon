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
const int T = 303;
int mat[T][T];
int n,m;

int edge(int i, int j) {
    if((i == 0 and j == 0) or (i == 0 and j == m-1) or (i==n-1 and j==0) or (i==n-1 and j==m-1)) return 2;
    return (i == 0 or j == 0 or i == n-1 or j == m-1? 3 : 4);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        bool ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int ok = edge(i,j);
                cin >> mat[i][j];
                if(mat[i][j] <= ok) mat[i][j] = ok;
                else ans = 0;
            }
        }
        if(!ans) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

