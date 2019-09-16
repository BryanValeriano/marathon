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
    int n; string s;
    cin >> n >> s;
    int tot = 0;
    int maxDown = 0;

    for(int i = 0; i < n; i++) {
        tot += (s[i] == '('? 1 : -1);
        maxDown = min(maxDown,tot);
    }

    cout << (tot == 0 and maxDown >= -1? "YES" : "NO") << endl;

    return 0;
}

