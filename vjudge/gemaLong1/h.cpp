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

const int T = 700;
int l[T];
int r[T];
bool dp[T][T];
bool vis[T][T];
int choose[T][T];
int n;

bool solve(int a, int b) {
    if(a == b) return (l[a] == 1);
    if(a > b) return 1;
    if(vis[a][b]) return dp[a][b];

    bool ok = 0;
    for(int k = 0; k <= b-a; k++) {
        if(2*k+1 >= l[a] and 2*k+1 <= r[a]) {
            ok = (solve(a+1,a+k) && solve(a+k+1,b));
            if(ok) { choose[a][b] = k; vis[a][b] = 1; return dp[a][b] = 1; }
        }
    }

    vis[a][b] = 1;
    return dp[a][b] = 0;
}

void build(int a, int b) {
    if(a > b) return;
    if(a == b) { printf("()"); return; }
    printf("(");
    build(a+1,a+choose[a][b]);
    printf(")");
    build(a+choose[a][b]+1,b);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", l+i, r+i);

    bool ans = 0;
    ans |= solve(0,n-1);

    if(ans) build(0,n-1), printf("\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}

