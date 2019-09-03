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

const int T = 2e5 + 4;

struct node {
    int pos, oper, id;

    bool operator < (const node &b) const {
        if(pos != b.pos) return pos < b.pos;
        return oper < b.oper;
    }
};

vector<node> v;
vector<int> ans;
bitset<T> vis;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a,0,i});
        v.pb({b,1,i});
    }

    sort(v.begin(), v.end());

    queue<int> fila;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].oper == 0) fila.push(v[i].id);
        else if(!vis[v[i].id]) {
            ans.pb(v[i].pos);
            while(!fila.empty()) {
                vis[fila.front()] = 1;
                fila.pop();
            }
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

