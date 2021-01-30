#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 2e9;
const int T = 1e5+5;

struct nd {
    ll pref,suf,mid,sm;
    ll qtdP,qtdS,qtdM,tot;
    ii best;
    int l,r;

    nd() {
        pref=suf=mid=sm=-INF;
        qtdP=1; qtdS=1; qtdM=1;
        tot=1; l=1; r=1;
        best = mk(-INF,-INF);
    }

    nd(int ll, int rr) {
        pref=suf=mid=sm=-INF;
        qtdP=1; qtdS=1; qtdM=1;
        l = ll; r = rr; tot=(r-l+1);
        best = mk(-INF,-INF);
    }

    void merge(nd &left, nd &right) {
        l = left.l;
        r = right.r;
        tot=(r-l+1);

        if(left.pref > left.sm + right.pref) {
            pref = left.pref;
            qtdP = left.qtdP;
        } else {
            pref = left.sm + right.pref;
            qtdP = left.tot+right.qtdP;
        }
        if(right.suf > right.sm + left.suf) {
            suf = right.suf;
            qtdS = right.qtdS;
        } else {
            suf = right.sm + left.suf;
            qtdS = right.tot+left.qtdS;
        }

        mid = left.suf + right.pref;
        qtdM = left.qtdS + right.qtdP;
        sm = left.sm + right.sm;
        best = max({mk(pref,qtdP),mk(suf,qtdS),mk(mid,qtdM),mk(sm,tot)});
        best = max({left.best,right.best,best});
    }
};

nd seg[4*T];
int v[T], a, b;

void build(int node, int i, int j) {
    seg[node] = nd(i,j);
    if(i == j) {
        seg[node].pref = seg[node].suf = v[i];
        seg[node].mid = seg[node].sm = v[i];
    } else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node].merge(seg[2*node],seg[2*node+1]);
    }
}

nd query(int node, int i, int j) {
    if(i > b or j < a) return nd(i,j);
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    nd at = nd(i,j);
    nd l = query(2*node,i,mid);
    nd r = query(2*node+1,mid+1,j);
    at.merge(l,r);
    return at;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;

    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> v[i];
        build(1,1,n);
        int q; cin >> q;
        while(q--) {
            cin >> a >> b;
            nd ans = query(1,1,n);
            cout << ans.best.fi << " " << ans.best.se << endl;
        }
    }
    return 0;
}
