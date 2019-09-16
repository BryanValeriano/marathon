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

int c1, r1, c2, r2,n;
int r,c;
int mov;
int mov2;
char mat[110][110];
bool flag;

bool isIn(int x, int y) {
    return (y >= c1)? (x >= 0 and x < r2) : (x >= 0 and x < r1);
}

int proxR(int y) {
    flag = !flag;
    mov2 *= -1;
    return ((!flag)? (y >= c1? r2-1 : r1-1) : 0);
}

tuple<int,int> next() {
    if(isIn(r+mov2,c)) return make_tuple(r+mov2,c);
    else return make_tuple(proxR(c+1),c+1);
}

void build(int qtd, char ok) {
    while(qtd--) {
        mat[r][c] = ok;
        tie(r,c) = next();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(mat, '.', sizeof mat);
    int x;
    cin >> c1 >> r1 >> c2 >> r2 >> n;

    if(c1&1) {
        r = r1-1;
        mov2 = -1;
        flag = 0;
    } else {
        r = 0;
        mov2 = 1;
        flag = 1;
    }

    for(int i = 0; i < n; i++) {
        cin >> x;
        build(x, 'a'+i);
    }

    cout << "YES" << endl;
    for(int i = 0; i < max(r1,r2); i++) {
        for(int j = 0; j < c1+c2; j++)
            cout << mat[i][j];
        cout << endl;
    }

    return 0;
}

