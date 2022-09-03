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
const int T = 2e5+5;
ll v[T], bin[T][5];
int n,m,k;

void pre() {
    for(int i = 0; i < T; i++) bin[i][0] = 1;
    for(int i = 0; i < 4; i++) bin[i][i] = 1;
    for(int i = 1; i < T; i++)
        for(int j = 1; j < 4; j++)
            bin[i][j] = bin[i-1][j-1]+bin[i-1][j];
}

ll choose(int z, int x) {
    if(x > z) return 0;
    return bin[z][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    pre();
    m = 3, k = 2;

    while(tc--) {
        cin >> n;
        ll ans = 0;

        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v,v+n);
        int l = 0;
        int r = 0;

        while(l < n) {
            while(r+1 < n && v[r+1]-v[l] <= k) r++;
            ans = (ans+choose(r-l,m-1));
            l++;
        }

        cout << ans << endl;
    }
    return 0;
}

