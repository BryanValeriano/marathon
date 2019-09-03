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
const int T = 1e3 + 10;
int n, m;
string p, t;
int pi[T];
int ans[T];

void pre() {
    p += '#';

    pi[0] = pi[1] = 0;
    for(int i = 2; i <= m; i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1])
            pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1])
            pi[i]++;
    }
}

void kmp() {
    pre();
    int k = 0;

    for(int i = 0; i < n; i++) {
        while(k > 0 and p[k] != t[i])
            k = pi[k];

        if(p[k] == t[i])
            k++;

        if(k == m)
            ans[i - m + 1] = 1;
    }
}


int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> n >> m >> q;
    cin >> t >> p;
    kmp();
    int a, b;
    for(int i = 0; i < n; i++) ans[i] += ans[i-1];
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        a--; b--;
        if(b-a+1 < m) { cout << 0 << endl; continue; }
        b = max(0, b-m+1);
        cout << ans[b] - (a-1 >= 0? ans[a-1] : 0) << endl;
    }
    return 0;
}

