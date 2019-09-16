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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

typedef struct node {
    ll n,m;
    ll result;

    node() {}

    node(ll n, ll m, ll r) :
        n(n), m(m), result(r) {}

}nd;

node operator * (node a, node b) {
    if(a.m != b.n) return node(a.n,a.m,INF);
    return node(a.n,b.m,a.n*b.m*a.m + a.result + b.result);
}

const int T = 11;
ll lin[T];
ll col[T];
nd dp[T][T];
int vis[T][T];
int choose[T][T];
int vez;


node solve(int l, int r) {
    if(l == r) return node(lin[l],col[l],0);
    if(vis[l][r] == vez) return dp[l][r];

    node best = solve(l,l) * solve(l+1,r);
    choose[l][r] = l;

    for(int i = l+1; i < r; i++) {
        node tmp = solve(l,i) * solve(i+1,r);
        if(tmp.result < best.result) {
            choose[l][r] = i;
            best = tmp;
        }
    }

    vis[l][r] = vez;
    return dp[l][r] = best;
}

void build(int l, int r) {
    if(l == r) cout << "A" + to_string(l+1);
    else {
        cout << "(";
        build(l,choose[l][r]);
        cout << " x ";
        build(choose[l][r]+1,r);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    int cont = 0;
    while(tc) {
        for(int i = 0; i < tc; i++) cin >> lin[i] >> col[i];
        vez++; solve(0,tc-1);
        cout << "Case " << ++cont << ": ";
        build(0,tc-1);
        cout << endl;
        cin >> tc;
    }
    return 0;
}

