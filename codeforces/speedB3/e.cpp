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

const int T = 3e5 + 2;
vector<int> topo[T];
int topoLido[T];
set<ii> bag;
vii hist;

int n,q;
ll tot;
ll totLido;
int point;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;

    int op,x;

    for(int j = 0; j < q; j++) {
        cin >> op >> x;
        if(op == 1) {
            topo[x].pb(j);
            bag.emplace(j,x);
            hist.eb(j,x);
            tot++;
        }

        else if(op == 2) {
            for(; topoLido[x] < topo[x].size(); topoLido[x]++) {
                ii ok = mk(topo[x][topoLido[x]],x);
                if(bag.count(ok)) totLido++, bag.erase(ok);
            }
        } 
        
        else {
            for(; point < x; point++) {
                if(bag.count(hist[point])) {
                    totLido++;
                    topoLido[hist[point].se]++;
                    bag.erase(hist[point]);
                }
            }
        }
        cout << tot - totLido << endl;
    }

    return 0;
}

