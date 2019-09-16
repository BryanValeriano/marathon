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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 3;

int n,m;
int at[T];
map<int,int> cor;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        at[i] = x;
        cor[x]++;
        if(cor[x] == n) { cout << 0 << endl; return 0; }
    }

    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x,y; cin >> x >> y;
        cor[at[x]]--;
        at[x] = y;
        cor[y]++;
        if(cor[y] == n) { cout << i << endl; return 0; }
    }

    cout << -1 << endl;

    return 0;
}

