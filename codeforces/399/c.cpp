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
const int T = (1<<11);
int v[2][T];

void solve(int x, bool turn) {
    int qtd = 0;
    memset(v[!turn], 0, sizeof v[!turn]);

    for(int i = 0; i < T; i++) {
        int l = qtd + 1;
        int r = qtd + v[turn][i];
        qtd += v[turn][i];
        if(r >= l) {
            int tmp = v[turn][i] - ((r>>1) - ((l-1)>>1));
            v[!turn][i] += v[turn][i] - tmp;
            v[!turn][i^x] += tmp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,k,x; cin >> n >> k >> x;

    while(n--) {
        int z; cin >> z;
        v[(k-1)&1][z]++;
    }
    while(k--) solve(x, k&1);

    int mini = INF;
    int maxi = -INF;
    for(int i = 0; i < T; i++) {
        mini = min(mini, (v[1][i]? i : mini));
        maxi = max(maxi, (v[1][i]? i : maxi));
    }

    cout << maxi << " " << mini << endl;
    return 0;
}

