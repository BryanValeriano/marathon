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
int n, m;
char M[T][T];

int mov[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
bool in(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

void solve(int i, int j) {
    for(int k = 0; k < 4; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(in(ii,jj) and M[ii][jj] == '.') {
            if(M[i][j] == 'B') { M[ii][jj] = 'W'; solve(ii,jj); }
            else { M[ii][jj] = 'B'; solve(ii,jj); }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vii track;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> M[i][j];
            if(M[i][j] == '.') track.eb(i,j);
        }
    }

    for(auto x : track) {
        if(M[x.fi][x.se] == '.') {
            M[x.fi][x.se] = 'B';
            solve(x.fi,x.se);
        }
    }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cout << M[i][j];
        cout << endl;
    }
    return 0;
}

