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

const int T = 10;
int n,m;
char mat[T][T];

int mov[3][2] = { {-1,0}, {0,-1}, {0,1} };

bool isIn(int x, int y) {
    return(x >= 0 and x < n and y >= 0 and y < m);
}

void dfs(int i, int j, int pos, string gol) {
    if(pos >= gol.size()) { cout << endl; return; }

    for(int k = 0; k < 3; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(isIn(ii,jj) and mat[ii][jj] == gol[pos]) {
            if(mov[k][0] == -1) cout << "forth";
            else if(mov[k][1] == -1) cout << "left";
            else cout << "right";
            if(pos != 6) cout << " ";
            dfs(ii,jj,pos+1,gol);
            break;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        int inix,iniy;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == '@') inix = i, iniy = j;
            }
        dfs(inix,iniy, 0, "IEHOVA#");
    }
    return 0;
}

