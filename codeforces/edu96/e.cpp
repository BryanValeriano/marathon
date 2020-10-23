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
const int T = 2e5+5;
const int N = 30;
int pos[N][T], point[N];
int bit[T];
bool vis[T];

void update(int pos) {
    for(; pos < T; pos += pos&(-pos)) bit[pos]++;
}

int tmp(int x) {
    int ans = 0;
    for(; x > 0; x -= x&(-x)) ans += bit[x];
    return ans;
}

ll query(int a, int b) {
    return tmp(b) - tmp(a);
}

void makePoint(string &s) {
    for(int i = 1; i < s.size(); i++) {
        int ok = s[i]-'a';
        pos[ok][point[ok]++] = i;
    }
    for(int i = 0; i < N; i++) point[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    s = "#" + s;

    makePoint(s);
    ll l = 1, r = n;
    ll ans = 0;

    while(r > 0) {
        int gol = s[r]-'a';
        int prox = pos[gol][point[gol]++];
        vis[prox] = 1;
        ans += prox-l-query(l,prox);
        update(prox);
        r--;
        while(l < n and vis[l]) l++;
    }

    cout << ans << endl;
    return 0;
}
