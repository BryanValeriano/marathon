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
const int T = 2e5 + 3;

ll v[T];
ll sum[4*T];
ll maxi[4*T];
ll a,b,val;
int n,q;

void build(int node, int i, int j) {
    if(i == j) {
        cin >> v[i];
        maxi[node] = sum[node] = v[i];
    } else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        sum[node] = sum[2*node] + sum[2*node+1];
        maxi[node] = max(maxi[2*node],maxi[2*node+1]);
    }
}

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) sum[node] = maxi[node] = v[i] = val;
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        sum[node] = sum[2*node] + sum[2*node+1];
        maxi[node] = max(maxi[2*node],maxi[2*node+1]);
    }
}

int mostLeft(int node, int i, int j) {
    if(i > b or j < a or maxi[node] < val) return n;
    int mid = (i+j) >> 1;
    if(i >= a and j <= b) {
        if(i == j) return i;
        return (maxi[2*node] >= val?
            mostLeft(2*node,i,mid) :
            mostLeft(2*node+1,mid+1,j));
    }
    return min(mostLeft(2*node,i,mid),mostLeft(2*node+1,mid+1,j));
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return sum[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid)+query(2*node+1,mid+1,j);
}

bool check(int at) {
    a = 0; b = at-1;
    ll tmp;
    if(b < a) tmp = 0;
    else tmp = query(1,0,n-1);
    return (tmp == v[at]);
}

int ask() {
    int at = 0;
    val = 0;
    while(at < n) {
        a = at, b = n-1;
        at = mostLeft(1,0,n-1);
        if(at == n) return -1;
        if(check(at)) return at+1;
        a = 0; b = at;
        val = query(1,0,n-1);
        at++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    build(1,0,n-1);
    while(q--) {
        cin >> a >> val;
        b = a;
        a--;b--;
        update(1,0,n-1);
        cout << ask() << endl;
    }
    return 0;
}

