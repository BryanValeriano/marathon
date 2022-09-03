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
typedef pair<int,char> ic;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 30;

bool vis[T][T];
int deg[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    string ans;
    ans = 'a';
    int last = 0;

    while(ans.size() < n) {
        int c = 0, best = INF;
        for(int i = 0; i < k; i++) {
            if(vis[last][i]) continue;
            if(best > deg[i]) { best = deg[i], c = i; }
        }
        if(best == INF) break;
        deg[last]++;
        vis[last][c] = 1;
        ans += (char)('a'+c);
        last = c;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            if(!vis[i][j]) cout << (char)('a'+i) << (char)('a'+j) << endl;
    for(int i = 1; ans.size() < n; i++) ans += ans[i];
    cout << ans << endl;
    return 0;
}

