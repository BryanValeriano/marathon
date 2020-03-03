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
typedef tuple<int,int,int> ti;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e6 + 10;
int seg[4*T];
int open[4*T];
int close[4*T];
string s;
int a,b;

void build(int node, int i, int j) {
    if(i == j) {
        if(s[i] == '(') open[node]++;
        else close[node]++;
    } else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);

        int ok = min(open[2*node],close[2*node+1]);

        seg[node] = seg[2*node] + seg[2*node+1] + ok;
        open[node] = open[2*node+1] + (open[2*node] - ok);
        close[node] = close[2*node] + (close[2*node+1] - ok);
    }
}

ti query(int node, int i, int j) {
    if(i > b or j < a) return make_tuple(0,0,0);
    if(i >= a and j <= b) return make_tuple(open[node],seg[node],close[node]);
    int mid = (i+j) >> 1;

    int lo,ls,lc;
    int  ro,rs,rc;
    int ok;

    tie(lo,ls,lc) = query(2*node,i,mid);
    tie(ro,rs,rc) = query(2*node+1,mid+1,j);
    ok = min(lo,rc);

    return make_tuple(ro+lo-ok, ls+rs+ok, lc+rc-ok);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;

    int n = s.size()-1;
    build(1,0,n);
    int q; cin >> q;
    while(q--) {
        cin >> a >> b;
        a--;b--;
        cout << get<1>(query(1,0,n))*2 << endl;
    }
    return 0;
}

