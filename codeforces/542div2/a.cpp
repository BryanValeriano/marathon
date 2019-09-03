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
    int n,x; cin >> n;
    int gol = n/2 + (n&1);
    int pos = 0;
    int neg = 0;

    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x > 0) pos++;
        else if(x < 0) neg++;
    }

    if(pos >= gol) cout << 1;
    else if(neg >= gol) cout << -1;
    else cout << 0;
    cout << endl;

    return 0;
}

