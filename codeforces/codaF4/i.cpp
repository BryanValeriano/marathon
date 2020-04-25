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

const int LIM = 77777;
const int T = 1e5 + 10;
int dp[T], tmp[T], peso[T], pai[T], old[T], used[T];
bool vis[T];
int n;

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

vector<int> gen() {
    int v[2] = {4,7};
    vector<int> ans;
    for(int i = 0; i < 2; i++) {
        int tmp = v[i];
        ans.pb(tmp);
        for(int j = 0; j < 2; j++) {
            tmp += v[j]*10;
            ans.pb(tmp);
            for(int k = 0; k < 2; k++) {
                tmp += v[k]*100;
                ans.pb(tmp);
                for(int p = 0; p < 2; p++) {
                    tmp += v[p]*1000;
                    ans.pb(tmp);
                    for(int z = 0; z < 2; z++) {
                        tmp += v[z]*10000;
                        ans.pb(tmp);
                        tmp -= v[z]*10000;
                    }
                    tmp -= v[p]*1000;
                }
                tmp -= v[k]*100;
            }
            tmp -= v[j]*10;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, INF, sizeof dp);

    vii v;
    int m;
    cin >> n >> m;
    init();

    while(m--) {
        int a,b;
        cin >> a >> b;
        join(a,b);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[find(i)]) tmp[peso[find(i)]]++;
        vis[find(i)] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(tmp[i]) {
            for(ll j = 1; j <= tmp[i]; j <<= 1) {
                v.eb(i*j,j);
                tmp[i] -= j;
            }
            if(tmp[i]) v.eb(i*tmp[i],tmp[i]);
        }
    }

    dp[0] = 0;
    for(auto x : v) {
        int val, vzs;
        tie(val,vzs) = x;
        for(int k = LIM; k-val >= 0; k--)
            dp[k] = min(dp[k],dp[k-val]+vzs);
    }

    vector<int> beuty = gen();
    int ans = INF;
    for(auto x : beuty) ans = min(ans,dp[x]);
    cout << (ans > n? -1 : ans-1) << endl;

    return 0;
}

