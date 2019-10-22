#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int> ti;
typedef vector<ti> vti;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 5;

int v[T];
vector<ii> g[T];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        g[a].eb(b,i+1);
    }
    
    priority_queue<ii, vii> pq;
    int acum = 0;

    for(int i = 0; i < T; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            ii x = g[i][j];
            v[x.fi+1]++;
            acum++;
            pq.emplace(x);
        }
        acum -= v[i];
        while(acum > k) {
            ii x = pq.top();
            v[x.fi+1]--;
            pq.pop();
            ans.pb(x.se);
            acum--;
        }
    }

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok << " ";
    cout << endl;

    
    return 0;
}

