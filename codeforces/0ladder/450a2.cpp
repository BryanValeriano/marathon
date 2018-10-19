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

int main() {
    ios::sync_with_stdio(false);
    double n, m;
    cin >> n >> m;
    ii maxi = mk(0, -INF);
    double aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        int tmp = ceil(aux/m); 
        if(tmp >= maxi.se) 
            maxi = mk(i, tmp);
    }
    cout << maxi.fi << endl;

    return 0;
}

