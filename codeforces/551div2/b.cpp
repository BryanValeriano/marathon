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

const int T = 103;
bitset<T> linha[T];
bitset<T> coluna[T];

int linM[T];
int colM[T];

int ans[T][T];

int n,m,h;

void duplo() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(ans[i][j]) {
                bitset<T> tmp = (coluna[j] & linha[i]);
                if(tmp.count()) {
                    for(int k = 0; k < T; k++) {
                        if(tmp[k]) { 
                            ans[i][j] = k; 
                            coluna[j][k] = linha[i][k] = 0;
                            break; 
                        }
                    }
                }
            }
        }
    }
}

void unit() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {

            if(ans[i][j] == 1) {

                bool flag = false;

                if(linha[i].count()) {
                    for(int k = 1; k <= min(colM[j],linM[i]); k++) {
                        if(linha[i][k]) {
                            ans[i][j] = k;
                            linha[i][k] = 0;
                            flag = true;
                            break;
                        }
                    }
                }

                if(!flag and coluna[j].count()) {
                    for(int k = 0; k <= min(linM[i],colM[j]); k++) {
                        if(coluna[j][k]) {
                            ans[i][j] = k;
                            coluna[j][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    int x;

    for(int i = 1; i<= m; i++) {
        cin >> x;
        coluna[i][x] = 1;
        colM[i] = max(colM[i], x);
    }

    for(int i = 1; i <= n; i++) {
        cin >> x; 
        linha[i][x] = 1;
        linM[i] = max(linM[i], x);
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> ans[i][j];
   
    duplo();
    unit();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }


    return 0;
}

