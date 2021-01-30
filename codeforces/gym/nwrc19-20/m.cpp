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
const int T = 2e3+2;
int v[T];
unordered_map<int,int> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        bag.clear();
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            bag[v[i]]++;
        }
        int ans = 0;
        for(int j = 0; j < n; j++) {
            bag[v[j]]--;
            for(int i = 0; i < j; i++) {
                int diff = v[j]-v[i];
                ans += bag[v[j]+diff];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

