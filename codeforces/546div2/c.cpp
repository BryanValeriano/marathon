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
const int T = 510;
int a[T][T];
int b[T][T];

map<int,int> dig[T+T];
map<int,int> dig2[T+T];

int main() {
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dig[i+j][a[i][j]]++;
        }


    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> b[i][j];
            dig2[i+j][b[i][j]]++;
        }

    for(int i = 1; i < T+T; i++) 
        for(auto x : dig[i]) 
            if(x.se != dig2[i][x.fi]) { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;

    return 0;
}

