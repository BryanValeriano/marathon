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

const int T = 2010;
ll v[T][T];

ll query(int i, int j, int m) {
    return v[i+m][j+m] - v[i+m][j-1] - v[i-1][j+m] + v[i-1][j-1];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    ll sum = -1;
    while(cin >> n) {
        if(sum != -1) cout << endl;
        cin >> m;
        sum = 0;
        m--;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> v[i][j];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];

        for(int i = 1; i + m <= n; i++)
            for(int j = 1; j + m <= n; j++) {
                ll x = query(i,j,m);
                cout << x << endl;
                sum += x;
            }


        cout << sum << endl;
    }

    return 0;
}

