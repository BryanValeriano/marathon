#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

const int T = 30;
const int N = 1e4 + 5;
int v[T];
int dp[N];
int n,m;

void solve(int val) {
    for(int i = 0; i <= val; i++)
        for(int k = 0; k < n; k++)
            if(i-v[k] >= 0) dp[i] = min(dp[i], dp[i-v[k]]+1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", v+i);

        for(int j = 1; j < N; j++) dp[j] = INF;
        solve(min(m,N-1));
        int at = 0, last = 0, ans = 0, r = INF;

        while(at < m) {
            at = 0;
            ans++;
            for(int i = 0; i < n; i++) {
                int x = last + v[i];
                if(m-x < N and m-x >= 0) r = min(r, ans+dp[m-x]);
                if(x > at and x <= m) at = x;
            }
            last = at;
        }
        printf("%d\n", min(r,ans));
    }
    return 0;
}

