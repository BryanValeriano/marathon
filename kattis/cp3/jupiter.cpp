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
const int N = 33;
const int T = 103;
int go[T], sz[N], d[N], lim[N][N];
int v[N][N];

void fuc() {
    cout << "impossible\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q,s;
    cin >> n >> q >> s;
    for(int i = 0; i < s; i++) cin >> go[i], go[i]--;
    for(int i = 0; i < q; i++) cin >> sz[i];

    for(int i = 0; i < n; i++) {
        cin >> d[i];
        int tmp;
        for(int j = 0; j < s; j++) {
            cin >> tmp;
            v[i][go[j]] += tmp;
        }
    }

    int bonus = 0;

    for(int t = n-1; t >= 0; t--) {
        for(int j = 0; j < q; j++) {
            if(v[t][j] > sz[j]) fuc();
            lim[t][j] = sz[j]-v[t][j];
            if(bonus) {
                int tmp = min(bonus,lim[t+1][j]);
                v[t][j] -= tmp;
                bonus -= tmp;
            }
            if(v[t][j]) d[t] -= v[t][j];
            if(d[t] < 0) fuc();
        }
        for(int j = 0; j < q; j++) lim[t][j] = min(lim[t][j],d[t]);
        bonus = d[t];
    }

    cout << "possible\n";

    return 0;
}

