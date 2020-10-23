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
const int T = 1e3+5;
string mat[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    n++;
    m = m*2+1;
    for(int i = 0; i < n; i++)
        getline(cin,mat[i]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << mat[i][j];
        cout << endl;
    }

    return 0;
}

