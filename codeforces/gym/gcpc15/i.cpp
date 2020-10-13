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

int main() {
    ios_base::sync_with_stdio(false);

    int w, s;
    cin >> w >> s;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> ps(w, vector<int>(x));
    for (int i = 0;i < w;i++) {
        for (int j = 0;j < x;j++) {
            cin >> ps[i][j];
        }
    }
    vector<int> ss(x, y);
    for (int i = 0;i < s;i++) {
        int d;
        for (int j = 0;j < x;j++) {
            cin >> d;
            ss[j] = min(ss[j], y - d);
        }
    }
    for (int i = 0;i < w;i++) {
        for (int j = 0;j < x;j++) {
            cout << min(ps[i][j], ss[j]) << " ";
        }
        cout << endl;
    }
    return 0;
}

