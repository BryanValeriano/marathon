#include <bits/stdc++.h>
using namespace std;

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
map<int,set<ii>> gaps;
set<int> piles;

int before(int x) {
    auto ok = piles.lower_bound(x);
    if(ok == piles.begin()) return -1;
    ok--;
    return *ok;
}

int after(int x) {
    auto ok = piles.lower_bound(x+1);
    if(ok == piles.end()) return -1;
    return *ok;
}

void del(int x, int y) {
    gaps[x-y].erase(mk(x,y));
    if(gaps[x-y].empty()) gaps.erase(x-y);
}

void add(int x) {
    int l = before(x);
    int r = after(x);
    if(l != -1 and r != -1) del(r,l);
    if(l != -1) gaps[x-l].insert(mk(x,l));
    if(r != -1) gaps[r-x].insert(mk(r,x));
    piles.insert(x);
}

void rem(int x) {
    int l = before(x);
    int r = after(x);
    if(l != -1) del(x,l);
    if(r != -1) del(r,x);
    if(l != -1 and r != -1) gaps[r-l].insert(mk(r,l));
    piles.erase(x);
}

int query(int x, int y) {
    //cout << x << " " << y << " = " << (y-x) << endl;
    return (y-x);
}


int solve() {
    if(piles.size() <= 2) return 0;
    auto best = gaps.rbegin();
    ii cords = *(best->se.begin());
    //cout << "BEST " << cords.fi << " " << cords.se << endl;
    return query(*piles.begin(),cords.se) + query(cords.fi, *piles.rbegin());
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    while(n--) {
        int x; cin >> x;
        add(x);
    }

    cout << solve() << endl;

    while(q--) {
        int op,x;
        cin >> op >> x;
        if(op) add(x);
        else rem(x);
        cout << solve() << endl;
    }

    return 0;
}

