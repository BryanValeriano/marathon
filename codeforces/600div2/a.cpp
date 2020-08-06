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
const int T = 1e5+2;
int a[T], b[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i], b[i] -= a[i];

        int last = b[0];
        vector<int> test;
        test.pb(last);

        for(int i = 1; i < n; i++) {
            if(b[i] != last) {
                last = b[i];
                test.pb(last);
            }
        }

        bool ans = 0;

        if(test.size() == 1) ans = (test[0] >= 0);
        else if(test.size() == 2) {
            ans = ((test[0] > 0 and test[1] == 0)
                    or (test[0] == 0 and test[1] > 0));
        }
        else if (test.size() == 3)
            ans = (test[1] > 0 and test[0] == 0 and test[2] == 0);

        cout << (ans? "YES" : "NO") << endl;
    }

    return 0;
}

