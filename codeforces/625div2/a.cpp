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
const int T = 102;

bool ok[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ok[i] |= x;
    }

    int a = 0, b = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x and !ok[i]) b++;
        if(!x and ok[i]) a++;
    }

    if(a == 0) {
        cout << -1 << endl;
    } else {
        cout << b/a+1 << endl;
    }

    return 0;
}

