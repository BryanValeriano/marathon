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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    ll lin[n + 3][m + 3];
    ll col[n + 3][m + 3];
    ll ans[max(n,m) + 3];
    memset(lin, 0, sizeof lin);
    memset(col, 0, sizeof col);
    memset(ans, 0, sizeof ans);
    char x;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> x;
            lin[i][j] += lin[i][j-1];
            col[i][j] += col[i-1][j];
            if(x == '.') {
                lin[i][j]++;
                col[i][j]++;
            } else lin[i][j] = col[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(lin[i][j] >= 1) ans[lin[i][j]]++;
            if(col[i][j] >= 2) ans[col[i][j]]++, ans[1]--;
        }
    }

    for(int i = max(n,m); i >= 1; i--)
        ans[i] += ans[i+1];
    for(int i = 1; i <= max(n,m); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

