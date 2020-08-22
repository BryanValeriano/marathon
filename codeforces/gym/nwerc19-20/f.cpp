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

vi id, sz;
void init(int x) {
    id.resize(n);
    sz.resize(n);
    for (int i = 0;i < x;i++) {
        id[i] = i;
        sz[i] = 1;
    }
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    id[a] = id[b];
    sz[b] += sz[a];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, list<int>> gs;
    int cs = n;
    vector<tuple<int, int, int>> ans;
    for (int i = 0;i < n;i++) {
        int m;
        cin >> m;
        for (int j = 0;j < m;j++) {
            int x;
            cin >> x;
            if (!gs[x].empty() and join(i, gs[x].back()) {
                ans.push_back(gs[x].back() + 1, i + 1, x);
                cs--;
            }
            gs[x].push_back(i);
        }
    }
    if (cs > 1) cout << "impossible" << endl;
    else {
        for (auto& [a, b, c] : ans) {
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}

