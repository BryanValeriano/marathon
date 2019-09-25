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

int n;
const int T = 3e4 + 4;
int cont[4*T+16];
ll len[4*T+16];
int a,b,val;
vector< tuple<int,int,int> >ys[T];

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) cont[node] += val;
    else if(i != j) {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
    }
    if(cont[node]) len[node] = (j-i+1);
    else if(i!=j) len[node] = len[2*node] + len[2*node+1];
    else len[node] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int x1,x2,y1,y2;

    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        ys[x1].eb(y1+1,y2,1);
        ys[x2].eb(y1+1,y2,-1);
    }

    ll last = 0;
    ll ans = 0;

    for(int i = 0; i < T; i++) {
        for(auto yss : ys[i]) {
            tie(a,b,val) = yss;
            ans += (ll)(i - last) * len[1];
            update(1,0,T-1);
            last = i;
        }
    }

    cout << ans << endl;

    return 0;
}

