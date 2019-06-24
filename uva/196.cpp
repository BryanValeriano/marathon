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

const int N = 2e4;
const int T = 1e3;

int mat[T][N];
vector<ii> g[T][N];
int in[T][N];
int n,m;


int conv2(string tmp) {
    int base = 26;
    int tam = tmp.size() - 1;
    int ans = 0;

    for(int i = 0; i < tmp.size(); i++) {
        if(tam == 0) ans += tmp[i] - 'A';
        else ans += (pow(base,tam))*(tmp[i] - 'A' + 1); 
        tam--;
    }
    
    return ans;
}

ii conv(string tmp) {
    string a = "",b = "";

    for(int i = 0; i < tmp.size(); i++) {
        if(tmp[i] >= 'A' and tmp[i] <= 'Z') a += tmp[i];
        else b += tmp[i];
    }

    return mk(stoi(b)-1, conv2(a));
}

void add(int i, int j, string tmp) {
    string t = "";

    for(int k = 1; k < tmp.size(); k++) {
        if(tmp[k] == '+') {
            ii x = conv(t);
            g[x.fi][x.se].eb(i,j);
            in[i][j]++;
            t = "";
        }
        else t += tmp[k];
    }

    ii x = conv(t);
    g[x.fi][x.se].eb(i,j);
    in[i][j]++;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> m >> n;
        string tmp;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) g[i][j].clear();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> tmp;
                if(tmp[0] == '=') {
                    mat[i][j] = 0;
                    add(i,j,tmp);
                } else {
                    mat[i][j] = stoi(tmp);
                }
            }
        }

        queue<ii> fila;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!in[i][j]) fila.emplace(i,j);

        while(!fila.empty()) {
            ii at = fila.front();
            fila.pop();

            for(int i = 0; i < g[at.fi][at.se].size(); i++) {
                ii v = g[at.fi][at.se][i];
                in[v.fi][v.se]--;
                mat[v.fi][v.se] += mat[at.fi][at.se];
                if(!in[v.fi][v.se]) fila.emplace(v);
            }
        }
       
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                cout << mat[i][j] << (j+1 < m? ' ' : '\n');
    }
            
    return 0;
}

