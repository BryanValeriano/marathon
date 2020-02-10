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

const int T = 1e3 + 5;
const int N = 1e4 + 5;

int vis[2][T];
vector<int> g[2][T];
vector<int> p[2][T];
char ans[T];
vii v[N];
int k,n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> k >> n;
    int x;
    char y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> x >> y;
            v[i].eb(x,(y == 'B'));
            p[(y == 'B')][x].pb(i);
        }
    }

    for(int i = 1; i <= k; i++) {
        if(p[0][i].size() and p[1][i].size()) {
            for(int j = 0; j < p[1][i].size()) {
                for(int z = 0; z < v[p[1][i][j]].size(); z++) {


            }
            for(int j = 0; j < p[0][i].size()) {

            }
        }
    }

    return 0;
}

