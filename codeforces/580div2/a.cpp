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

int main() {
    ios_base::sync_with_stdio(false);
    int n,m, x;
    int maxa = 0, maxb = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x, maxa = max(maxa,x);
    cin >> m;
    for(int i = 0; i < m; i++) cin >> x, maxb = max(maxb,x);
    cout << maxa << " " << maxb << endl;
    return 0;
}

