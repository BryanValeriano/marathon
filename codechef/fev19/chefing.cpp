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
const int T = 30;
bool visit[T];
int tot[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string s;
    while(tc--) {
        int n; cin >> n;
        getline(cin, s);
        memset(tot, 0, sizeof tot);
        for(int i = 0; i < n; i++) {
            memset(visit, false, sizeof visit);
            getline(cin, s);
            for(int i = 0; i < s.size(); i++) 
                visit[s[i] - 'a'] = true;
            for(int i = 0; i < T; i++) tot[i] += visit[i];
        }
        int ans = 0;
        for(int i = 0; i < T; i++) 
            if(tot[i] == n) ans++;
        cout << ans << endl;
    }
    return 0;
}

