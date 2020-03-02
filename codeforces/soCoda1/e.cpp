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

const int T = 1e5 + 5;

struct node {
    node *l;
    node *r;

    int val;

    node () {
        l = NULL;
        r = NULL;
        val = 0;
    }
};

node *seg[T];
int n,m;

int query(node *at, int i, int j, int a, int b, int val) {
    if(i > b or j < a) return 0;

    if(i >= a and j <= b) {
        at->val = max(at->val,val);
        return at->val;
    }

    if(!at->l) at->l = new node();
    if(!at->r) at->r = new node();

    int mid = (i+j) >> 1;
    int x = max(query(at->l,i,mid,a,b,val),query(at->r,mid+1,j,a,b,val));
    at->val = max(at->l->val,at->r->val);

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int ans = 0;

    for(int i = 1; i <= n; i++) seg[i] = new node();

    while(m--) {
        int a,b,w; cin >> a >> b >> w;
        int best = (w? query(seg[a],0,T,0,w-1,0) : 0);
        ans = max(ans,best+1);
        query(seg[b],0,T,w,w,best+1);
    }
    cout << ans << endl;
    return 0;
}

