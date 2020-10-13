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

    int n, k;
    cin >> n >> k;
    vector<int> next(k + 1, 0), prev(k + 1, 0);
    int x;
    int last = 0;
    for (int i = 0;i < n;i++) {
        cin >> x;
        if (next[x] or prev[x]) {
            if (last != x and next[x] < x) {
                next[prev[x]] = next[x];
                prev[next[x]] = prev[x];
                next[x] = 0;
                next[last] = x;
                prev[x] = last;
                last = x;
            }
        }
        else {
            prev[x] = last;
            next[last] = x;
            last = x;
        }
    }
    for (int x = next[0];x;x = next[x]) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

