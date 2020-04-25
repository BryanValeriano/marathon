#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 102;
int xc,yc,r;
int xa,ya,xb,yb;

bool isIn(int i, int j) {
    return (abs(xc-i) + abs(yc-j) <= r) or (i >= xa and i <= xb and j >= ya and j <= yb);
}

int main() {
    ios_base::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    cin >> xc >> yc >> r;
    cin >> xa >> ya >> xb >> yb;
    if(xa > xb) swap(xa,xb);
    if(ya > yb) swap(ya,yb);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << (isIn(i,j)? '#' : '.');
        cout << endl;
    }



    return 0;
}

