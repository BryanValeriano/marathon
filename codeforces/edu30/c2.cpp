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
int mat[T][T];
int col[T];
int qtd[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];

    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++)
            mat[i][j] += mat[i-1][j];

    for(int j = 1; j <= m; j++) {
        int t = 0;
        for(int i = 1; i <= n; i++) {
            if(mat[i][j] > mat[i-1][j]) {
                int prox = min(k,n-i+1);
                prox = i + prox - 1;
                int tmp = mat[prox][j] - mat[i-1][j];
                if(tmp > col[j]) {
                    col[j] = tmp;
                    qtd[j] = t++;
                }
            }


    
    
    return 0;
}

