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

int n, r, c;
const int N = 2000;
vector<string> room(N, string(N, ' '));
vector<vector<vector<int>>> laser(N, vector<vector<int>>(N, vector<int>(4, 0)));
bool go(int x, int y, int dir, int val = 1) {
    laser[x][y][dir] = val;
    if (room[x][y] != '.') {
        dir ^= 1 + 2 * (room[x][y] == '\\');
        laser[x][y][dir] = val;
    }
    else if (val == -1) {
        for (int i = (dir + 1) & 1;i < 4;i += 2) {
            if (laser[x][y][i] == 1) {
                return true;
            }
        }
    }
    int nx = x + (dir == 2) - (dir == 0);
    int ny = y + (dir == 1) - (dir == 3);
    if (nx >= n or ny < 0) return false;
    if (nx < 0) return val == -1 and c == ny;
    if (ny >= n) return val == 1 and r == nx;
    return go(nx, ny, dir, val);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> c >> r;
    r--, c--;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> room[i][j];
        }
    }
    bool ans;
    if (!(ans = go(0, c, 2))) {
        ans = go(r, n - 1, 3, -1);
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}

