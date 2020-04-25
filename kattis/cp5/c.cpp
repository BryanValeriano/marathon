#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
    vector<int> v,c;
    node(int n) : v(n,0), c(n,0) {}

};

bool hasEq(const node &a, const node &b) {
    bool ok1 = 1, ok2 = 1;
    for(int i = 0; i < a.v.size(); i++)
        ok1 &= (a.v[i] == b.v[i]) and (a.c[i] == b.c[i]);
    for(int i = 0; i < a.v.size(); i++)
        ok2 &= (a.v[i] == b.c[i]) and (a.c[i] == b.v[i]);
    return ok1 or ok2;
}

vector<node> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int w,l,k;
    cin >> w >> l >> k;
    for(int i = 0; i < k; i++) {
        node tmp = node(l);
        int mini = INF;
        for(int p = 0; p < l; p++) {
            int x; cin >> x;
            tmp.v[p] += x;
            mini = min(mini,x);
        }
        for(int p = 0; p < l; p++) tmp.v[p] -= mini;
        for(int p = 0; p < l; p++) {
            int x; cin >> x;
            tmp.c[p] += x+mini;
        }

        bool ok = 0;
        for(int p = 0; p < l/2; p++)
            if(tmp.c[p] > tmp.c[l-p-1]) ok = 1;

        if(ok) {
            reverse(tmp.v.begin(),tmp.v.end());
            reverse(tmp.c.begin(),tmp.c.end());
        }

        ok = 0;
        for(auto x : bag) ok |= hasEq(x,tmp);
        if(!ok) bag.pb(tmp);

    }
    cout << bag.size() << endl;
    return 0;
}

