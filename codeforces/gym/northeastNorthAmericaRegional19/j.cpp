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

bool intersect(int x, int a, int b, int y, int c, int d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return a <= y and y <= b and c <= x and x <= d;
}

int main() {
    ios_base::sync_with_stdio(false);

    int l, n;
    cin >> l >> n;
    set<tuple<int, int, int>> segs[2];
    int x = 0, y = 0, dir = 0, last = 0;
    bool ans = false;
    for (int i = 0;i < n;i++) {
        int l;
        char c;
        cin >> l >> c;
        if (c == 'C') {
            dir--;
            if (dir == -1) dir = 3;
        }
        else {
            dir++;
            if (dir == 4) dir = 0;
        }
        int nx = x + (l - last) * ((dir == 1) - (dir == 3));
        int ny = y + (l - last) * ((dir == 0) - (dir == 2));
        for (auto& p : segs[~dir & 1]) {
            if (ans) break;
            int h, a, b;
            tie(h, a, b) = p;
            if (intersect(h, a, b, dir & 1 ? x : y, dir & 1 ? y : x, dir & 1 ? ny : nx)) ans = true;
        }
        segs[dir & 1].emplace(dir & 1 ? x : y, dir & 1 ? y : x, dir & 1 ? ny : nx);
        x = nx;
        y = ny;
        last = l;
    }
    cout << (ans ? "GHOST" : "SAFE") << endl;
    return 0;
}

