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

const int T = 1e3 + 4;

int n,m;
int mat[T][T];

bool check(int t) {
    t--;

    for(int i = 1; i <= n; i++) {
        int k = i+t;
        if(k > n) break;
        for(int j = 1; j <= m; j++) {
            int l = j+t;
            if(l > m) break;
            int x = mat[k][l] - mat[i-1][l] - mat[k][j-1] + mat[i-1][j-1];
            if(x <= 1) return 1;
        }
    }

    return 0;
}
 
int main() {
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &mat[i][j]);
                mat[i][j] += mat[i-1][j] + mat[i][j-1];
                mat[i][j] -= mat[i-1][j-1];
            }
        }

        int l = 1, ans = 0;
        int r = min(n,m);

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }

        printf("%d\n", ans);
    }

    return 0;
}

