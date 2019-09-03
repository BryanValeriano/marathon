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
const int N = 500 + 5;
int r, c;
char m[N][N];

int mov[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool in(int x, int y) {
    return(x >= 0 and x < r and y >= 0 and y < c);
}

bool safe(int x, int y) {
    return m[x][y] != 'W';
}

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c;
    vii track;
    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) {
            cin >> m[i][j];
            if(m[i][j] == 'S') track.eb(i,j);
        }
    for(auto sheep : track) {
        for(int k = 0; k < 4; k++) {
            int ii = sheep.fi + mov[k][0];
            int jj = sheep.se + mov[k][1];
            if(!in(ii,jj)) continue;
            if(!safe(ii,jj)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(m[i][j] == '.') cout << 'D';
            else cout << m[i][j];
        }
        cout << endl;
    }
    return 0;
}

