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
const int T = 1e5+5;
int pos[T];
bool vis[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            pos[x] = i;
            vis[i] = 0;
        }

        int next = -1;
        int at = 0;
        bool ans = 1;

        for(int i = 1; i <= n; i++) {
            //cout << next << " " << pos[i] << endl;
            if(next != -1 and pos[i] != next) ans = 0;
            at = pos[i];
            vis[at] = 1;
            if(at+1 > n or vis[at+1]) next = -1;
            else next = at+1;
        }

        cout << (ans? "Yes\n" : "No\n");
    }
    return 0;
}

