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
const int T = 2e5 + 10;
int v[T];

struct node {
    int t,l,r;

    node(int t, int l, int r) :
        t(t), l(l), r(r) {}
};

vector<node> query;

int solve(int pos) {
    for(int i = query.size() - 1; i >= 0; i--) {
        int t = query[i].t; int l = query[i].l; int r = query[i].r;
        if(l > pos or r < pos) continue;

        if(t == 1) {
            if(pos == l) pos = r;
            else pos--;
        }

        else pos = r - (pos - l);
    }

    return v[pos];
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, m;
    cin >> n >> q >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int t,l,r;
    for(int i = 0; i < q; i++) {
        cin >> t >> l >> r;
        query.eb(t,l,r);
    }
    while(m--) {
        cin >> t;
        cout << solve(t) << " ";
    }
    cout << endl;
    return 0;
}

