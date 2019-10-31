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
typedef pair<char,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 4;
ii seg[4*T];
int n,a,b,d;

ii best(const ii &x, const ii &y) {
    if(x.fi != y.fi) return (x.fi > y.fi? x : y);
    else return (x.se < y.se? x : y);
}

void build(int node, int i, int j) {
    if(i == j) cin >> seg[node].fi, seg[node].se = i;
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = best(seg[2*node],seg[2*node+1]);
    }
}

ii query(int node, int i, int j) {
    if(i > b or j < a) return mk('0',INF);
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return best(query(2*node,i,mid),query(2*node+1,mid+1,j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    while(n and d) {
        d = n-d;
        build(1,1,n);
        int last = 1;
        string ans;
        while(d) {
            a = last;
            b = n-d+1;
            ii x = query(1,1,n);
            ans += x.fi;
            last = x.se+1;
            d--;
        }
        cout << ans << endl;
        cin >> n >> d;
    }
    return 0;
}

