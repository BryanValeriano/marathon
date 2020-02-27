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

const int T = 101;
vector<int> v[T];
int n,m;

bool equal(int x, int y) {
    for(int i = 0; i < m; i++)
        if(v[x][i] != v[y][i]) return 0;
    return 1;
}

bool ok(int ini, int fim) {
    int ini2 = fim+1;
    int fim2 = ini2 + (fim-ini);

    if(fim2 >= n) return 0;

    for(int i = fim2, j = ini; i >= ini2, j <= fim; i--, j++) {
        if(!equal(i,j)) return 0;
    }

    return (fim2 == n-1? 1 : ok(ini,fim2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        v[i].reserve(m);
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }

    for(int i = 0; i < n; i++) {
        if(ok(0,i)) { cout << i+1 << endl; return 0; }
    }

    cout << n << endl;

    return 0;
}

