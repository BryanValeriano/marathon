#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1000 + 3;
char mat[T][T];
char pen[T][T];

bool check(int i, int j) {
    if(mat[i-1][j] == '#' and mat[i][j-1] == '#' 
        and mat[i+1][j] =='#' and mat[i][j+1] == '#'
        and mat[i-1][j-1] == '#' and mat[i+1][j+1] == '#'
        and mat[i-1][j+1] == '#' and mat[i+1][j-1] == '#') 
            return true;
        
    
    return false;
}

void pinta(int i, int j) {
    pen[i-1][j] = pen[i][j-1] = pen[i+1][j] = pen[i][j+1] = pen[i-1][j-1] = pen[i+1][j+1] =
     pen[i-1][j+1] = pen[i+1][j-1] = '#';
}


int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pen[i][j] = '.';
            cin >> mat[i][j];
        }
    }
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1;j++) {
            if(check(i,j)) {
                pinta(i, j);
            }
        }
    }
    int cont = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m;j++) {
            if(mat[i][j] == pen[i][j])
                cont++;
        }
    }
    if(cont == n*m) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

