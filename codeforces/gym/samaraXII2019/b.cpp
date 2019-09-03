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

string s[2];
vector<int> v;
bool vis[2][1010];
int mov[4][2] = { {1,0}, {0,1}, {-1, 0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 0 and y >= 0 and y < s[0].size() and x < 2);
}

void dfs(int x, int y) {
    vis[x][y] = 1;

    for(int k = 0; k < 4; k++) {
        int xx = x + mov[k][0];
        int yy = y + mov[k][1];
        if(isIn(xx,yy) and !vis[xx][yy] and s[xx][yy] == '#') dfs(xx,yy);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s[0] >> s[1];
    int val;

    for(int i = 0; i < s[0].size(); i++) {
        int a = 0, b = 0;
        if(s[0][i] == '#') a = 1;
        if(s[1][i] == '#') b = 1;

        if(a == 1 and b == 0) val = 3;
        else if(a == 1 and b == 1) val = 2;
        else if(a == 0 and b == 1) val = 1;
        else val = 0;

        v.pb(val);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < s[0].size(); i++) {
        if(v[i] == 3) s[0][i] = '#', s[1][i] = '.';
        if(v[i] == 2) s[0][i] = '#', s[1][i] = '#';
        if(v[i] == 1) s[0][i] = '.', s[1][i] = '#';
        if(v[i] == 0) s[0][i] = '.', s[1][i] = '.';
    }

    int p = 0;

    for(int i = 0; i < s[0].size(); i++)
        for(int j = 0; j < 2; j++)
            if(!vis[j][i] and s[j][i] == '#') p++, dfs(j,i);

    if(p <= 1) {
        cout << "YES" << endl;
        cout << s[0] << endl << s[1] << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

