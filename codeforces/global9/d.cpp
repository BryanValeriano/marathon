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
const int T = 1e3+3;
int vis[T];
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        memset(vis,0,sizeof vis);
        int n; cin >> n;
        stack<int> dup;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            vis[v[i]]++;
        }

        vector<int> ans;
        int w = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                while(v[w] < i and vis[v[w]] < 2) w++;
                ans.pb(w);
                vis[v[w]]--;
                v[w++] = i;
                vis[i]++;
            }
        }

        cout << " ----------------- ";
        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;

        ans.pb(n-1);
        int last = v[n-1];
        v[n-1] = n;
        int corn = n-1;

        for(int i = 0; i < 2*n and corn; i++) {
            bool ok = last == corn;
            ans.pb(last-ok);
            int tmp = v[last-ok];
            v[last-ok] = last;
            last = tmp;
            if(ok) corn--;
            for(int j = 0; j< n; j++) cout << v[j] << " ";
                cout << endl;
        }

        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}

