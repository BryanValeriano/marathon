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
const int INF = 2e9;
const double PI = acos(-1.0);
const int T = 2e5 + 100;
int va[T], vb[T];
int mini[4*T], maxi[4*T];
int a,b,n;

void build(int node, int i, int j) {
    if(i==j) maxi[node] = va[i], mini[node] = vb[i];
    else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        maxi[node] = max(maxi[2*node],maxi[2*node+1]);
        mini[node] = min(mini[2*node],mini[2*node+1]);
    }
}

ii query(int node, int i, int j) {
    if(b < a) return mk(-INF,INF);
    if(i > b or j < a) return mk(-INF,INF);
    if(i >= a and j <= b) return mk(maxi[node],mini[node]);
    int mid = (i+j)>>1;
    ii x = query(2*node,i,mid);
    ii y = query(2*node+1,mid+1,j);
    return mk(max(x.fi,y.fi),min(x.se,y.se));
}

bool check(int x, int y) {
    a = x; b = y;
    ii ok = query(1,0,n-1);
    return(ok.fi <= ok.se);
}

bool check2(int x, int y) {
    a = x; b = y;
    ii ok = query(1,0,n-1);
    return(ok.fi == ok.se);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> va[i];
    for(int i = 0; i < n; i++) cin >> vb[i];

    build(1,0,n-1);
    ll res = 0;

    for(int i = 0; i < n; i++) {
        int l = i+1;
        int r = n-1;
        int ans = -1;
        int ans2 = -1;

        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(i,mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }

        l = i+1;
        r = ans;

        while(l<=r) {
            int mid = (l+r)>>1;
            if(check2(i,mid)) ans2 = mid, r = mid-1;
            else l = mid+1;
        }

        if((~ans) and (~ans2)) res += (ll)(ans-ans2+1);
        if(va[i]==vb[i])res++;
    }

    cout << res << endl;

    return 0;
}

