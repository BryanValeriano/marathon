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
        int q,m; cin >> q >> m;
        vector<set<char>> ans(q);

        for(int i = 0; i < q; i++)
            for(char j = 'A'; j <= 'D'; j++)
                ans[i].insert(j);

        while(m--) {
            for(int i = 0; i < q; i++) {
                char a,b; cin >> a >> b;
                if(b == 'T') ans[i].clear(), ans[i].insert(a);
                else ans[i].erase(a);
            }
        }
        for(int i = 0; i < ans.size(); i++) {
            auto x = ans[i];
            if(x.size() == 1) cout << *x.begin();
            else cout << "?";
            cout << (i+1 < ans.size()? " " : "\n");
        }
    }
    return 0;
}

