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

const int T = 70;

int g[T][T];
int mov[8][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };

bool isIn(char a, char b) {
    return (a >= 'a' and a <= 'h' and b >= '1' and b <= '8');
}

int getId(char a, char b) {
    int ans = (a - 'a') * 8;
    ans += b - '1';
    return ans;
}

void floyd() {
    for(int k = 0; k < T; k++)
        for(int i = 0; i < T; i++)
            for(int j = 0; j < T; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void pre() {
    for(char i = 'a'; i <= 'h'; i++) {
        for(char j = '1'; j <= '8'; j++)  {
            g[getId(i,j)][getId(i,j)] = 0;
            for(int k = 0; k < 8; k++) {
                char ii = i + mov[k][0];
                char jj = j + mov[k][1];
                if(isIn(ii,jj)) {
                    g[getId(i,j)][getId(ii,jj)] = 1;
                    g[getId(ii,jj)][getId(i,j)] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    memset(g, INF, sizeof g);
    string a,b;
    pre();
    floyd();
    while(cin >> a) {
        cin >> b;
        cout << "To get from " << a << " to " << b << " takes ";
        cout << g[getId(a[0],a[1])][getId(b[0],b[1])];
        cout << " knight moves." << endl;
    }
    return 0;
}

