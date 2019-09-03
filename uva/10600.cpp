#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
 
struct node {
    int x,y,p,id;
 
    bool operator < (const node &b) const {
        return p > b.p;
    }
};
 
const int T = 105;
int pai[T];
int peso[T];
vector<int> vis;
int n,m;
 
void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}
 
int find(int x) {
    return(x == pai[x]? x : pai[x] = find(pai[x]));
}
 
void join(int x, int y) {
    x = find(x);
    y = find(y);
 
    if(peso[x] < peso[y]) swap(x,y);
 
    pai[y] = x;
    peso[x] += peso[y];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc, x, y, p; cin >> tc;
    while(tc--) {
        init();
        vis.clear();
        cin >> n >> m;
        priority_queue<node, vector<node> > pq;
        for(int i = 0; i < m; i++) {
            cin >> x >> y >> p;
            pq.push({x,y,p,i});
        }
 
        int mini = 0;
        int mini2 = INF;
        int cp = n;
 
        priority_queue<node, vector<node> > s;
        s = pq;
 
        while(cp > 1) {
            node at = s.top();
            s.pop();
            if(find(at.x) != find(at.y)) {
                cp--;
                vis.pb(at.id);
                join(at.x,at.y);
                mini += at.p;
            }
        }
       
        for(int i = 0; i < vis.size(); i++) {
            cp = n;
            int tmp = 0;
            init();
            s = pq;
 
            while(cp > 1 and !s.empty()) { 
                node at = s.top();
                s.pop();
                if(find(at.x) != find(at.y) and at.id != vis[i]) {
                    cp--;
                    join(at.x,at.y);
                    tmp += at.p;
                }
            }
 
            if(cp == 1) mini2 = min(mini2, tmp);
        }
        cout << mini << " " << mini2 << endl;
    }
    return 0;
}
