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

const int T = 1e3 + 5;

string v[T];
int score[T];
ll best[T][5];
int n,m;

map<char,int> bag;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < m; i++) cin >> score[i];

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            best[j][v[i][j]-'A'] += score[j];
        }

    ll ans = 0;        

    for(int i = 0; i < m; i++) {
        ll at = 0;
        for(int j = 0; j < 5; j++) at = max(at,best[i][j]);
        ans += at;
    }

    cout << ans << endl;

    return 0;
}

