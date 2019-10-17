#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 3;
int v[T];
int cont = 0;
vector<int>seg[4*T];
int a, b, k;
vector<int>ans[T];

void build(int node, int i, int j) {
    seg[node].resize(j-i+1);
    if(i == j) seg[node][0] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        merge(seg[2*node].begin(), seg[2*node].end(), seg[2*node+1].begin(), seg[2*node+1].end(), seg[node].begin());
    }
}

void query(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b){
        ans[cont+1].resize(ans[cont].size() + seg[node].size());
        merge(ans[cont].begin(), ans[cont].end(), seg[node].begin(), seg[node].end(), ans[cont+1].begin());
        cont++;
        return;
    }
    int mid = (i+j) >> 1;
    query(2*node,i,mid);
    query(2*node+1,mid+1,j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    build(1,0,n-1);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= cont; j++)
            ans[cont].clear();
        cont = 0;
        cin >> a >> b >> k;
        a--; b--; k--;
        query(1,0,n-1);
        cout << (ans[cont].size() < k? -1 : ans[cont][k]) << endl;
    }
    return 0;
}

