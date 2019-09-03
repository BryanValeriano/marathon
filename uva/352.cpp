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

const int T = 28;

char mat[T][T];
bool vis[T][T];
int mov[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
int n;

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < n);
}

void dfs(int i, int j) {
    vis[i][j] = true;

    for(int k = 0; k < 8; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(isIn(ii,jj) and mat[ii][jj] == '1' and !vis[ii][jj]) dfs(ii,jj);
    }
}
        

int main() {
    ios::sync_with_stdio(false);
    int cont = 0;
    while(cin >> n) {
        memset(vis, 0, sizeof vis);
        int ans = 0;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                cin >> mat[i][j];


        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] and mat[i][j] == '1') ans++, dfs(i,j);

        cout << "Image number " << ++cont << " contains " << ans << " war eagles." << endl;
    }
    return 0;
}

