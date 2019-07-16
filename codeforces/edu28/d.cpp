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

const int T = 500*500 + 5;
const int N = 505;

int n,m,k,q;

vii que;
int x[T], y[T];
int mat[N][N];

bool check(int mid) {
    memset(mat,0,sizeof mat);

    for(int i = 0; i < q; i++) {
        if(que[i].fi > mid) break;
        int id = que[i].se;
        mat[x[id]][y[id]] = 1;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];


    bool ok = 0;

    for(int i = 1; i + k - 1 <= n; i++)
        for(int j = 1; j + k - 1 <= m; j++)
            if(mat[i+k-1][j+k-1] - mat[i-1][j+k-1] - mat[i+k-1][j-1] + mat[i-1][j-1] == k*k) ok = 1;
   
    return ok;

}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> n >> m >> k >> q;

    for(int i = 0; i < q; i++) {
        cin >> x[i] >> y[i] >> t;
        que.eb(t,i);
    }

    sort(que.begin(), que.end());

    int l = 0;
    int r = 1e9 + 5;
    int ans = r;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    
    cout << (ans > 1e9? -1 : ans) << endl;
    return 0;
}

