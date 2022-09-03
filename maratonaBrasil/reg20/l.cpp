#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 42;
const int N = 28;

char g[T][T];
ll ans[T][T];
int freq[N];
string v[T];
int qtd[T];
int dir[4][2] = { {1,0}, {0,1}, {1,1}, {1,-1} };
int n,m;

bool isIn(int i, int j) {
    return(i >= 0 and i < n and j >= 0 and j < m);
}

void go(ll pos, int d, int i, int j) {
    ans[i][j] |= (1ll<<pos);
    for(int k = 1; k < qtd[pos]; k++) {
        int ii = i + k*dir[d][0];
        int jj = j + k*dir[d][1];
        ans[ii][jj] |= (1ll<<pos);
    }

}

void solve(int pos, int d) {
    memset(freq,0,sizeof freq);
    int ok = 0;

    for(int i = 0; i < qtd[pos]; i++) {
        freq[v[pos][i]-'A']++;
        if(freq[v[pos][i]-'A'] == 1) ok++;
    }

    int tmp = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tmp = 0;
            freq[g[i][j]-'A']--;
            tmp += (freq[g[i][j]-'A'] == 0);

            for(int k = 1; k < qtd[pos]; k++) {
                int ii = i + k*dir[d][0];
                int jj = j + k*dir[d][1];
                if(!isIn(ii,jj)) break;
                freq[g[ii][jj]-'A']--;
                tmp += (freq[g[ii][jj]-'A'] == 0);
            }

            if(tmp == ok) go(pos,d,i,j);

            freq[g[i][j]-'A']++;
            for(int k = 1; k < qtd[pos]; k++) {
                int ii = i + k*dir[d][0];
                int jj = j + k*dir[d][1];
                if(!isIn(ii,jj)) break;
                freq[g[ii][jj]-'A']++;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> v[i];
        qtd[i] = v[i].size();
        for(int j = 0; j < 4; j++) solve(i,j);
    }

    int r = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            r += __builtin_popcount(ans[i][j]) > 1;
        }

    cout << r << endl;
    return 0;
}

