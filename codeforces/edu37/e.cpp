#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 3;

int n,m;
set<ii> bag;
vector<int> ans;
set<int> nxt;
int sz;

int bfs(int at) {
    sz++;
    int ans = 1;
    nxt.erase(at);

    queue<int> fila;
    fila.push(at);
    
    while(!fila.empty() and sz < n) {
        at = fila.front();
        fila.pop();

        vector<int> del;
        for(int ok : nxt) {
            if(bag.count(mk(min(at,ok),max(at,ok)))) continue;
            del.pb(ok);
            sz++;
            ans++;
            fila.push(ok);
        }
        for(auto ok : del) nxt.erase(ok);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) nxt.insert(i);
    
    while(m--) {
        int a,b; cin >> a >> b;
        bag.emplace(min(a,b),max(a,b));
    }


    for(int i = 1; i <= n; i++) 
        if(nxt.count(i)) ans.pb(bfs(i));

    cout << ans.size() << endl; 
    if(ans.size()) sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

