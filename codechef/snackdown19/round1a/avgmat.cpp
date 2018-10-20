#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 305;
char mat[T][T];
int resp[2*T];
int cord[4][2] = { {1,1}, {-1,-1}, {1,-1}, {-1,1} };
int n, m;

bool isIn(int a, int b) {
    return (a >= 0 and b  >= 0 and a < n and b < m);
}

void test(int a, int b) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                if(i == j and j == 0) continue;
                if(i == 0 and k > 1) continue;
                if(j == 0 and k > 1) continue;
                int ii = i * cord[k][0];
                int jj = j * cord[k][1];
                if(isIn(a+ii,b+jj) and mat[a+ii][b+jj] == '1') 
                    resp[abs(ii) + abs(jj)]++;
            }
        }
    } 
    mat[a][b] = '0';
}
            
 
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 1; i <= n + m - 2; i++) resp[i] = 0;
        vii track; 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == '1') track.eb(i,j);
            }
        for(int i = 0; i < track.size(); i++)  
            test(track[i].fi, track[i].sec);
        for(int i = 1; i <= n + m - 2; i++) 
            cout << resp[i] << " ";
        cout << endl;
    }
    return 0;
}

