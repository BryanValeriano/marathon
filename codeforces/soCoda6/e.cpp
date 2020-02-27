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
const int T = 1e3+2;

bool dp[2][T];
int pre[T][T];

int main() {
    int n,m,x;
    scanf("%d %d", &n, &m);

    bool last = 0;

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            pre[i][j] = (i+j) % m;

    while(n--) {
        scanf("%d", &x);
        x %= m;

        dp[!last][x] = 1;

        for(int i = 0; i < m; i++) {
            if(dp[last][i]) {
                if(i == 0) { printf("YES\n"); return 0; }
                dp[!last][pre[i][x]] = 1;
                dp[!last][i] = 1;
            }
        }

        last = !last;
    }


    if(dp[last][0]) printf("YES\n");
    else printf("NO\n");

    return 0;
}

