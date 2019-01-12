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
const int T = 110;
int v[T];
int n;

int solve(int x, int y) {
    int ans = 0;
    int vv[T];
    for(int i = 0; i < 2*n; i++) vv[i] = v[i];
    vv[x] = vv[y] = 0;
    sort(vv, vv+(2*n));
    for(int i = 0; i < 2*n; i+=2) ans += vv[i+1] - vv[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = INF;
    for(int i = 0; i < 2*n; i++) cin >> v[i];
    for(int i = 0; i < 2*n-1; i++)
        for(int j = i + 1; j < 2*n; j++)
            ans = min(ans, solve(i,j));
    cout << ans << endl;
    return 0;
}

