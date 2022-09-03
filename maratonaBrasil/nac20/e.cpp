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
int v[T], dp[T];
ii seg[4*T+4];
priority_queue<ii> pq;
int a,b,val,n;

void build(int node, int l, int r) {
    if(l == r) seg[node] = mk(v[l],l);
    else {
        int mid = (l+r)>>1;
        build(2*node, l, mid);
        build(2*node+1,mid+1, r);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }
}

ii query(int node, int l, int r, bool flag) {
    if(l > b or r < a) return mk(0,0);

    int mid = (l+r)>>1;
    if(!(r-l)) return (seg[node].fi > val? seg[node] : mk(0,0));

    if(flag) {
        if(seg[2*node].fi > val && mid >= a) return query(2*node,l,mid,flag);
        if(seg[2*node+1].fi > val && mid < b) return query(2*node+1,mid+1,r,flag);
    } else {
        if(seg[2*node+1].fi > val && mid < b) return query(2*node+1,mid+1,r,flag);
        if(seg[2*node].fi > val && mid >= a) return query(2*node,l,mid,flag);
    }

    return mk(0,0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pq.emplace(v[i],i);
    }

    build(1, 0, n-1);
    while(!pq.empty()) {
        ii top = pq.top();
        pq.pop();

        a = 0; b = top.se-1;
        val = top.fi;
        ii left = query(1,0,n-1,0);

        a = top.se+1; b = n-1;
        ii right = query(1,0,n-1,1);
        int ans = -1;

        if(left.fi && right.fi) {
            if(top.se - left.se < right.se - top.se) ans = dp[left.se];
            else if(right.se - top.se < top.se - left.se) ans = dp[right.se];
            else if(right.fi > left.fi) ans = dp[right.se];
            else ans = dp[left.se];
        }
        else if(left.fi) ans = dp[left.se];
        else if(right.fi) ans = dp[right.se];
        dp[top.se] = ans+1;
    }

    for(int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << endl;
    return 0;
}

