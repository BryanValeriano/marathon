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

const int T = 2e5 + 5;
int monster[T];
int seg[4*T];
int maxi[T];
vii heroes;
int n,m,a,b;

void build(int node, int i, int j) {
    if(i == j) seg[node] = monster[i];
    else {
        int mid = (i + j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = max(seg[2*node], seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return max(query(2*node,i,mid), query(2*node+1,mid+1,j));
}

bool check(int start, int days) {
    a = start;
    b = min(n-1,start+days-1);
    int x = query(1,0,n-1);
    int y = maxi[days];
    return(y >= x);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        heroes.clear();

        cin >> n;
        for(int i = 0; i < n; i++) cin >> monster[i];
        build(1,0,n-1);

        cin >> m;
        for(int i = 0; i < m; i++) {
            int x,y; cin >> x >> y;
            heroes.eb(y,x);
        }

        for(int i = 0; i < m; i++) maxi[heroes[i].fi] = max(maxi[heroes[i].fi],heroes[i].se);
        for(int i = n; i >= 0; i--) maxi[i] = max(maxi[i],maxi[i+1]);

        int start = 0;
        int z = 0;
        bool wat = 0;

        while(start <  n) {
            int l = 1;
            int r = n-start;
            int ans = 0;

            while(l <= r) {
                int mid = (l+r) >> 1;
                if(check(start,mid)) ans = mid, l = mid+1;
                else r = mid-1;
            }

            if(ans == 0) {
                cout << -1 << endl;
                wat = 1;
                break;
            }

            start += ans;
            z++;
        }

        if(!wat) cout << z << endl;

        for(int i = 0; i <= n; i++) maxi[i] = 0;
    }
    return 0;
}

