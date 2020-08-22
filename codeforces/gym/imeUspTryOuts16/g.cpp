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
const int T = 1e5+5;
const int N = 1e7;
int root[T], fim[T], ini[T], L[N], R[N], seg[N];
int val, pos, nodes;

int build(int l, int r) {
    int at = nodes++;
    if(l == r) seg[at] = 0;
    else {
        int m = (l+r) >> 1;
        L[at] = build(l,m);
        R[at] = build(m+1,r);
        seg[at] = 0;
    }
    return at;
}

int update(int i, int l, int r) {
    int at = nodes++;
    if(l==r) seg[at] = val;
    else {
        int m = (l+r)>>1;
        if(pos <= m) {
            L[at] = update(L[i],l,m);
            R[at] = R[i];
        } else {
            L[at] = L[i];
            R[at] = update(R[i],m+1,r);
        }
    }
    return at;
}

int query(int i, int l, int r) {
    if(r < pos or l > pos) return 0;
    if(l >= pos and r <= pos) return seg[i];
    else {
        int m = (l+r)>>1;
        return query(L[i],l,m)+query(R[i],m+1,r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    root[0] = build(0,T-1);
    ini[0] = 0;
    fim[0] = 0;
    for(int i = 1; i <= q; i++) {
        char op;
        int ver;
        cin >> op >> ver;
        if(op == 'E') {
            cin >> val;
            pos = fim[ver]+1;
            ini[i] = ini[ver]+(ver==0);
            fim[i] = fim[ver]+1;
            root[i] = update(root[ver],0,T-1);
        } else {
            pos = ini[ver];
            cout << query(root[ver],0,T-1) << endl;
            ini[i] = ini[ver]+1;
            fim[i] = fim[ver];
            val = 0;
            root[i] = update(root[ver],0,T-1);
        }
    }
    return 0;
}

