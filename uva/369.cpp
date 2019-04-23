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

const int T = 110;
int bc[T][T];

int bin(int n, int m) {
    for(int i = 0; i <= n; i++) bc[i][0] = 1;
    for(int j = 0; j <= n; j++) bc[j][j] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];

    return bc[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    while(n or m) {
        cout << n << " things taken " << m << " at a time is " << bin(n,m) << " exactly." << endl;
        cin >> n >> m;
    }
    return 0;
}

