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
const int T = 2e5 + 6;

int a[T], t[T];
int b[T], p[T];
int pi[T];
int n,m,ans;

void pre() {
    p[m] = 2e9;
    for(int i = 2; i <= m; i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
    }
}

void kmp() {
    pre();
    int k = 0;
    for(int i = 1; i < n; i++) {
        while(k > 0 and p[k] != t[i]) k = pi[k];
        if(p[k] == t[i]) k++;
        if(k == m) ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if(m == 1) { cout << n << endl; return 0; }

    for(int i = 0; i < n; i++) cin >> a[i], t[i] = a[i] - (i-1 >= 0? a[i-1] : a[i]);
    for(int i = 0; i < m; i++) cin >> b[i], p[i] = b[i] - (i-1 >= 0? b[i-1] : b[i]);
    m--;
    for(int i = 0; i <= m; i++) p[i] = p[i+1];
    kmp();
    cout << ans << endl;
    return 0;
}

