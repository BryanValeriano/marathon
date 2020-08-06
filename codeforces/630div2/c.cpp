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
const int T = 2e5+3;
const int K = 30;
int bag[T][K];
int vis[T],pai[T], peso[T];
int n,k;

int find(int x) {
    return (pai[x]==x?x:pai[x]=find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void init() {
    for(int i = 0; i < n; i++) {
        pai[i] = i;
        peso[i] = 1;
        memset(bag[i],0,sizeof bag[i]);
        vis[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        string s; cin >> s;
        init();
        int l = 0, r = n-1;
        while(l < r) join(l++,r--);
        for(int i = 0; i < n-k; i++) join(i,i+k);
        for(int i = 0; i < n; i++)
            bag[find(i)][s[i]-'a']++;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[find(i)]) continue;
            vis[find(i)] = 1;
            int best = 0;
            for(int j = 0; j < K; j++) {
                best = max(best,bag[find(i)][j]);
            }
            ans += (peso[find(i)]-best);
        }
        cout << ans << endl;
    }
    return 0;
}

