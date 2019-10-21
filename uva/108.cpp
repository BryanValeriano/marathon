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

const int T = 103;
int v[T][T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> v[i][j];
            v[i][j] += (v[i-1][j] + v[i][j-1] - v[i-1][j-1]);
        }

    int ans = -INF;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = i; k <= n; k++)
                for(int l = j; l <= n; l++)
                    ans = max(ans, v[k][l] - v[i-1][l] - v[k][j-1] + v[i-1][j-1]);

    cout << ans << endl;



    return 0;
}

