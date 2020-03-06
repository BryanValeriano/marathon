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
const int T = 105;
int g[T][T];
int col[T];
int row[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    int r = 0, c = 0;
    for(int i = 0; i < n; i++) cin >> row[i], r ^= row[i];
    for(int i = 0; i < m; i++) cin >> col[i], c ^= col[i];

    if(r != c) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    r = 0;

    for(int i = 0; i < m-1; i++) {
        g[0][i] = col[i];
        r ^= g[0][i];
    }
    g[0][m-1] = r ^ row[0];

    r = g[0][m-1];

    for(int i = 1; i < n-1; i++) {
        g[i][m-1] = row[i];
        r ^= g[i][m-1];
    }
    g[n-1][m-1] = r^col[m-1];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}

