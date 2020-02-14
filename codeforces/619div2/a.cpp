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
        string a,b,c; cin >> a >> b >> c;
        bool f = 1;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] == c[i] or b[i] == c[i]) continue;
            else f = 0;
        }

        cout << (f? "YES" : "NO") << endl;
    }
    return 0;
}

