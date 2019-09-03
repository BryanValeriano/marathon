#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 
typedef pair<int,int> ii;
typedef pair<double, ii> node;
typedef long long ll;
const int INF = 0x3f3f3f3f;
 
const int T = 755;
int xx[T];
int yy[T];
int pai[T];
int peso[T];
 
int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}
 
void join(int x, int y) {
    x = find(x);
    y = find(y);
 
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
 
    pai[y] = x;
    peso[x] += peso[y];
}
 
void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        init();
        int n,x,y,cpt; cin >> n;
        cpt = 0;
 
        for(int i = 0; i < n; i++)
            cin >> xx[i] >> yy[i];
 
        int m; cin >> m;
 
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            x--;y--;
            if(find(x) != find(y)) cpt++;
            join(x,y);
        }
 
        priority_queue<node, vector<node>, greater<node> > pq;
 
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(find(i) != find(j))
                    pq.emplace(hypot(abs(xx[i] - xx[j]), abs(yy[i] - yy[j])), ii(i,j));
 
        if(cpt == n-1) {
            cout << "No new highways need" << endl;
            if(tc) cout << endl;
            continue;
        }
       
        while(cpt < n-1) {
            node at = pq.top();
            pq.pop();
            if(find(at.se.fi) != find(at.se.se)) {
                join(at.se.fi, at.se.se);
                cpt++;
                cout << at.se.fi+1 << " " << at.se.se+1 << endl;
            }
        }
       
        if(tc) cout << endl;
    }        
 
    return 0;
}
