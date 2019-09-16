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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 5e3 + 2;
string s[T];
vector<int> pos[T];
int inimigos[T];
int qtd[T];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++)
            if(s[i][j] == '1') qtd[i]++, pos[i].pb(j);
    }

    int ans = INF;
    int id = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(qtd[j] != qtd[i]) { inimigos[i]++, inimigos[j]++; continue; }
            for(int  k = 0; k < pos[i].size(); k++)
                if(pos[i][k] != pos[j][k]) { inimigos[i]++, inimigos[j]++; break; }
        }
        if(!(qtd[i] >= 8 and qtd[i] <= 15)) inimigos[i] = INF;
        if(ans > inimigos[i]) ans = inimigos[i], id = i;
    }

    if(ans == INF) {
        for(int i = 0; i < m; i++) cout << (i < 15? '1' : '0');
        cout  << endl;
    } else cout << s[id] << endl;

    return 0;
}

