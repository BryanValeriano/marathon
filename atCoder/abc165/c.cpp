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
const int T = 12;
const int N = 51;
int v[T];
int a[N], b[N], c[N], d[N];
int n,m,q;

int calc() {
    int ans = 0;
    for(int i = 0; i < q; i++)
        if(v[b[i]] - v[a[i]] == c[i]) ans += d[i];
    return ans;
}

int solve(int casa, int last) {
    if(casa > n) return calc();
    int ans = 0;
    for(int i = last; i <= m; i++) {
        v[casa] = i;
        ans = max(ans, solve(casa+1,i));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    cout << solve(1,1) << endl;
    return 0;
}

