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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        int p = 0, ii = 0;
        string x;
        for(int i = 0; i < n; i++) {
            x += s[i];
            if((s[i] - '0')&1) ii++;
            if(ii == 2) break;
        }
        if(ii == 2) cout << x << endl;
        else cout << -1 << endl;
    }

    return 0;
}

