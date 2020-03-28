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
const int T = 4100;
const int N = 13;
const int K = 102;

int cost[N];
bool vis[T];
int qtd[T];
int pre[T];
int ans[T][K];
int n,m,q;

int id(string s) {
    int x = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '1') x += (1 << i);
    return x;
}

void pp() {
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < n; j++) {
            pre[i] += cost[j];
            if(i & (1 << j)) pre[i] -= cost[j];
        }
    }
}

void calc(int x) {
    vis[x] = 1;
    for(int i = 0; i < T; i++) {
        if(qtd[i]) {
            int d = pre[x^i];
            if(d > 100) continue;
            ans[x][d] += qtd[i];
        }
    }
    for(int i = 1; i <= 100; i++) ans[x][i] += ans[x][i-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> cost[i];
    pp();

    while(m--) {
        string s; cin >> s;
        qtd[id(s)]++;
    }

    while(q--) {
        string s; cin >> s;
        int k; cin >> k;
        int x = id(s);
        if(!vis[x]) calc(x);
        cout << ans[x][k] << endl;
    }

    return 0;
}

