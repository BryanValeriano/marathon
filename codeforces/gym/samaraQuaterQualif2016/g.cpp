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
const int T = 2e5 + 5;

struct node {
    int w,c,id,type;
    
    bool operator < (const node &b) const {
        if(w != b.w) return w > b.w;
        if(c != b.c) return c > b.c;
        if(type != b.type) return type > b.type;
        return id < b.id;
    }
};

vector<node> bag;
int ans[T];
set<ii> axes;

int main() {
    ios::sync_with_stdio(false);

    int n,a,b; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        bag.pb({a,b,i,0});
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        bag.pb({a,b,i,1});
    }

    sort(bag.begin(), bag.end());

    for(int i = 0; i < bag.size(); i++) {
        if(bag[i].type == 1) axes.insert(ii(bag[i].c, bag[i].id));
        else {
            auto low = axes.lower_bound(ii(bag[i].c,0));
            if(low == axes.end()) { cout << -1 << endl; return 0; }
            ans[bag[i].id] = low->se + 1;
            axes.erase(low);
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

