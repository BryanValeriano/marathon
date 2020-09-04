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
const int T = 3e3+4;
const int N = 5;
ll choose[T][N];
vector<int> g[T];

void pre() {
    for(int i = 0; i < T; i++) choose[i][0] = 1;
    for(int i = 0; i < N; i++) choose[i][i] = 1;

    for(int i = 1; i < T; i++)
        for(int j = 1; j < N; j++)
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
}

void build(vector<int> &preB, vector<int> &a, vector<int> &b) {
    int l = 0, r = 0;
    int n = a.size();
    int m = b.size();

    while(l < n and r < m) {
        if(r) preB[r] = preB[r-1];
        while(l+1 < n and a[l] < b[r]) l++;
        preB[r] += l;
        r++;
    }
}

ll calc(vector<int> &a, vector<int> &b) {
    int i,j,k,l;
    i = j = 0;
    k = l = 1;
    int n = a.size();
    int m = b.size();
    ll ans = 0;

    vector<int> preB(b.size(),0);
    build(preB, a, b);

    while(max(j,l) < m and max(i,k) < n) {
        while(i+1 < n and a[i+1] < b[j]) i++;
        while(k+1 < n and a[k] < b[j]) k++;
        while(l+1 < m and b[l] < a[k]) l++;
        if(a[i] < b[j] and b[j] < a[k] and a[k] < b[l]) {
            cout << a[i] << " " << b[j] << " " << a[k] << " " << b[l] << " = ";

            cout << (i+1)*(preB[m-1]-preB[j]) << endl;
            ans += (i+1)*(preB[m-1]-preB[j]);
            cout << (preB[m-1]-preB[j]) << endl;
        }
        j = max(l,j+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    pre();
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <=  n; i++) g[i].clear();
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            g[x].pb(i);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += choose[g[i].size()][4];
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                //cout << i << " " << j << " = " << calc(g[i],g[j]) << endl;
                ans += calc(g[i],g[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

