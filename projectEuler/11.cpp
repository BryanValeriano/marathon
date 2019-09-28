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

int mov[4][2] = { {-1,0}, {0,1}, {1,1}, {-1,1} };
ll mat[20][20];

bool isIn(int i, int j) {
    return(i >= 0 and i < 20 and j >= 0 and j < 20);
}

ll solve(int x, int y) {
    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        ll ok = 1;
        for(int j = 0; j < 4; j++) {
            int ii = x + mov[i][0];
            int jj = y + mov[i][1];
            if(isIn(ii,jj)) ok *= mat[ii][jj];
            else ok = 0;
        }
        ans = max(ans,ok);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            cin >> mat[i][j];
    
    ll ans = 0;

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            ans = max(ans,solve(i,j));
    
    cout << ans << endl;  
    return 0;
}

