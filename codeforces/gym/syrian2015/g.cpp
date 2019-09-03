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

const int T = 110;

char m[4][3*T];
int mov[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} }; 

int dfs(int i, int j) {
    int ans = 0;
    for(int k = 0; k < 8; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(m[ii][jj] == '*') ans += 4;
    }
    return ans;
}
        


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        for(int i = 0; i < 3; i++) 
            for(int j = 0; j < 3*n; j++) 
                cin >> m[i][j];
   
        int ans = 0;


        for(int i = 1; i < 3*n; i += 3)
            ans = max(ans, dfs(1,i));

        cout << ans << endl;
    } 
    return 0;
}

