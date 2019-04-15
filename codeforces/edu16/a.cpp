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

bool isIn(int c, int z) {
    return (c >= 'a' and c <= 'h' and z >= 1 and z <= 8);
}

int mov[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int c,z;
    c = s[0];
    z = s[1] - '0';
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        int cc = c + mov[i][0];
        int zz = z + mov[i][1];
        if(isIn(cc,zz)) ans++;
    }
    cout << ans << endl;
    return 0;
}

