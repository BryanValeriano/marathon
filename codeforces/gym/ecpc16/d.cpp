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
const int T = 21;
ll choose[T][T];

void pre() {
    for(int i = 0; i < T; i++)
        choose[i][0] = choose[i][i] = 1;
    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
}

int main() {
    freopen("popcorn.in","r",stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    pre();
    while(tc--) {
        int n,m; cin >> n >> m;
        cout << choose[n][m] << endl;
    }
    return 0;
}

