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

struct node{
    int l,r,pos;

    node(int l, int r, int pos) :
        l(l), r(r), pos(pos) {}
};

vector<node> query;

bool cmp(node &a, node &b) {
    if(a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

bool cmp2(node &a, node &b) {
    if(a.pos != b.pos) return a.pos < b.pos;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int q; cin >> q;
        query.clear();
        int l,r;
        for(int i = 0; i < q; i++) {
            cin >> l >> r;
            query.eb(l,r,i);
        }
        sort(query.begin(), query.end(), cmp);
        int maxidir = query[0].r;
        bool flag = true;
        for(auto x : query) {
            if(maxidir < x.l) {
                flag = false;
                break;
            }
            else maxidir = max(maxidir, x.r);
        }
        if(flag) { cout << -1 << endl; continue; }
        sort(query.begin(), query.end(), cmp2);
        for(auto x : query) {
            if(x.l > maxidir) cout << 2 << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

