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
const int T = 102;

char mat[T][T];
char ans[T][T];

int l,c,f,n,m,k,tot;
char z;

char next(char x) {
    if(x == 'z') return 'A';
    if(x == 'Z') return '0';
    return x+1;
}

void prox() {
    if((c == 0 and l&1) or (c == m-1 and !(l&1))) l++;
    else if(l&1) c--;
    else c++;
}

void bota(int ck, int qtd) {
    if(!ck or tot == n*m) return;
    tot++;
    ans[l][c] = z;
    if(mat[l][c] == 'R') qtd--;
    prox();

    if(!qtd) { 
        if(ck-1 > 0) { z = next(z); bota(ck-1,f); }
        return;
    } else bota(ck,qtd);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> m >> k;
        tot = l = c = 0, z = 'a';
        int p = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                p += (mat[i][j] == 'R');
            }
        
        int x = 0;
        int y = 0;
        int a = 0;
        int b = 0;
        a = p/k;
        b = a+1;
        y = p%k;
        x = k-y;
        
        f = a; bota(x,a);
        if(y) z = next(z);
        f = b; bota(y,b);

        while(tot < n*m) {
            ans[l][c] = z;
            prox();
            tot++;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cout << ans[i][j];
            cout << endl;
        }
    }
    
    return 0;
}

