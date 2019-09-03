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
const int T = 12;
char mat[T][T];
int n, m;
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
bool tem(int i, int j) {
    return(i >= 0 and i < n and j >= 0 and j < m and mat[i][j] == 'P');
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 'W') {
                for(int k = 0; k < 4; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][1];
                    if(tem(ii,jj)) { ans++; break; }
                }
            }
    cout << ans << endl;
    return 0;
}

