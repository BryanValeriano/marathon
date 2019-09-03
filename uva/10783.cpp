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

const int T = 102;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    for(int i = 1; i < T; i++) {
        v[i] += v[i-1];
        if(i&1) v[i] += i;
    }

    int tc,a,b,cont; cin >> tc;
    cont = 0;

    while(tc--) {
        cin >> a >> b;
        cout << "Case " << ++cont << ": " << v[b] - v[max(a-1,0)] << endl;
    }

    return 0;
}

