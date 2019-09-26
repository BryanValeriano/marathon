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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 3;
int u[T];
int freq[T];
int n,m;
vti que;

void last() {
    set<int> pos;
    for(int i = 1; i <= n; i++) {
        pos.insert(i);
        u[i] = 0;
    }

    for(int i = que.size()-1; i >= 0; i--) {
        if(!pos.size()) break;

        int x,l,k;
        tie(x,l,k) = que[i];

        int ll = x-k; 
        int rr = x+k;
        vector<int> del;

        for(auto i = pos.lower_bound(ll); i != pos.end() and *i <= rr; i++) {
            u[*i] = l;
            del.pb(*i);
        }

        for(auto ok : del) pos.erase(ok);
    }

}

int sweep() {
    vector<ii> line[n+3];

    for(int i = 0; i < que.size(); i++) {
        int x,l,k;
        tie(x,l,k) = que[i];
        line[max(1,x-k)].eb(l,1);
        line[min(n+1,x+k+1)].eb(l,-1);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(auto ok : line[i]) {
            int l, val;
            tie(l,val) = ok;
            freq[l] += val;
        }
        ans += (freq[u[i]] == 1);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        que.clear();
        for(int i = 0; i < m; i++) {
            int x,l,k; cin >> x >> l >> k;
            freq[l] = 0;
            que.eb(x,l,k);
        }
        last();
        int ans = sweep();
        cout << n-ans << endl;
    }
    return 0;
}

