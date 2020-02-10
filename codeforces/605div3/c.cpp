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

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    bool vis[26];
    ll ans = 0;
    string s; cin >> s;
    memset(vis,0,sizeof vis);

    for(int i = 0; i < k; i++) {
        char x; cin >> x;
        vis[x-'a'] = 1;
    }

    ll cont = 0;

    for(int i = 0; i < s.size(); i++) {
        if(vis[s[i]-'a']) cont++;
        else {
            ans += (cont*(cont+1))>>1;
            cont = 0;
        }
    }

    ans += (cont*(cont+1))>>1;

    cout << ans << endl;

    return 0;
}

