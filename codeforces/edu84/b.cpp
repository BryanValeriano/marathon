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
    int n;
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        set<int> king;
        set<int> princ;
        for(int i = 1; i <= n; i++) king.insert(i), princ.insert(i);
        bool ans = 0;
        for(int i = 1; i <= n; i++) {
            int k; cin >> k;
            bool ok = 0;
            for(int j = 0; j < k; j++) {
                int x; cin >> x;
                if(!ok and king.count(x)) {
                    king.erase(x);
                    princ.erase(i);
                    ok = 1;
                }
            }
        }
        cout << (king.empty()? "OPTIMAL" : "IMPROVE") << endl;
        if(!king.empty()) cout << *princ.begin() << " " << *king.begin() << endl;

    }
    return 0;
}

