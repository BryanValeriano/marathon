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
const int T = 5*10e5+5;
const int N = 1e7+5;
const int M = 1e9+2;
int seg[N], le[N], ri[N];

int v[T], ve[T];
int n,k,a,b,val,t;

bool impossible() {
    for(int i = 1; i <= k; i++) {
        cout << ve[i] << " " << ve[i-1] << endl;
        cout << v[ve[i]] << " " << v[ve[i-1]] << endl;
        cout << (ve[i] - ve[i-1] + 1) << " " << (v[ve[i]] - v[ve[i-1]] + 1) << endl;
        if(v[ve[i]] <= v[ve[i-1]]) return true;
        if(ve[i] - ve[i-1] + 1 >= v[ve[i]] - v[ve[i-1]] + 1) return true;
    }
    return false;
}

int query(int node, int i, int j) {
    if(!seg[node]) return seg[node];
    if(i >= a and j <= b) return seg[node];
    else {
        int ans = 0;
        int mid = (i+j)>>1;
        if(!le[node]) le[node] = ++t, ri[node] = ++t;
        if(mid >= a) ans = max(ans, query(le[node],i,mid));
        if(mid < b) ans = max(ans, query(ri[node],mid+1,j));
        return ans;
    }
}

void update(int node, int i, int j) {
    if(i >= a and j <= b) seg[node] = max(seg[node],val);
    else {
        int mid = (i+j)>>1;
        if(!le[node]) le[node] = ++t, ri[node] = ++t;
        if(mid >= a) update(le[node],i,mid);
        if(mid < b) update(ri[node],mid+1,j);
        seg[node] = max(seg[le[node]], seg[ri[node]]);
    }
}

int maxCrescSubSeq(int l, int r) {
    int offset = v[l-1]+1;
    int ans = 0;
    for(int i = l; i <= r; i++) {
        int x = 0;
        if(offset <= v[i]-1 and v[i] < v[r+1]) {
            a = offset;
            b = v[i]-1;
            x = query(0,-M,M);
            a = b = i;
            val = x+1;
            ans = max(ans,x+1);
            update(0,-M,M);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k += 2; n += 2;

    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i < k; i++) cin >> ve[i];

    v[0] = -INF;
    v[n] = INF;
    ve[k] = n;

    if(impossible()) { cout << -1 << endl; return 0; }
    int ans = 0;

    for(int i = 1; i <= k; i++)
        if(ve[i-1]+1 <= ve[i]-1)
            ans += maxCrescSubSeq(ve[i-1]+1, ve[i]-1);

    cout << ans << endl;
    return 0;
}

