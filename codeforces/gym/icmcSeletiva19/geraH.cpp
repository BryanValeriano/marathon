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

const int n = 3;
int mat[10][10];
int a[3];
map<ii,int> bag;

void solve(int i) {
    if(i > 2) {
        if(a[i-2]*a[i-2] >= a[i-3] * a[i-1]) {
            bag[mk(a[i-2],a[i-1])]++;
        } else return;
    }

    if(i == n) return;

    for(int j = 0; j <= 2; j++) {
        a[i] = j;
        solve(i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve(0);
    int i = 0;
    for(auto ok : bag) bag[ok.fi] = i++;

    for(auto ok : bag) {
        ii x = ok.fi;
        for(int y = 0; y <= 2; y++) {
            if(x.se*x.se >= x.fi*y) {
                mat[bag[x]][bag[mk(x.se,y)]]++;;
            }
        }
    }
    cout << "matID[9][9] = { ";
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << " {";
        for(int j = 0; j < 10; j++) cout << mat[i][j] << (j+1 < 10? ", " : " ");
        cout << "} " << (i+1 < 10? "," : "") << endl;
    }
    cout << "}; " << endl;
    return 0;
}

