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

const int T = 1e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int gol, gol2, n;
    ll sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];
    gol = sum/n;
    gol2 = gol;
    if(sum % n != 0) gol2 = gol+1;

    ll sob = 0;
    ll desce = 0;
    for(int i = 0; i < n; i++) {
        int x = v[i] - gol;
        int y = v[i] - gol2;
        int z;
        if(abs(x) < abs(y)) z = x;
        else z = y;
        if(z < 0) desce += abs(z);
        else sob += z;
    }

    cout << max(sob,desce) << endl;

    return 0;
}

