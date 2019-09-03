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
 
const int T = 3e5 + 3;
 
struct node {
    int id;
    unordered_set<int> pos;
    
    bool operator < (const node &b) const {
        return pos.size() > b.pos.size();
    }
};
 
node v[T];
vii bag;
int n,m;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a,b;
 
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        bag.eb(a,b);
        v[a].pos.insert(i);
        v[b].pos.insert(i);
    }
 
    sort(v, v+n);
 
    for(int i = 0; i < m; i++) {
        if(v[i].pos.size() < m/2) break;
 
        int x = -2,y = -2;
 
        for(int i = 0; i < m; i++) {
            if(x == -1 and y == -1) break;
            if(!v[i].pos.count(i)) {
                if(x == -2) {
                    x = bag[i].fi;
                    y = bag[i].se;
                } else {
                    if(bag[i].fi != x and bag[i].se != x) x = -1; 
                    if(bag[i].fi != y and bag[i].se != y) y = -1; 
                }
            }
        }
        if(x != -1 or y != -1) { cout << "YES" << endl; return 0; }
    }
 
    cout << "NO" << endl;
 
    return 0;
}
 
