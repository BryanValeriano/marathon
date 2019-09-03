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
    int x, y;
    cin >> x >> y;
    if(!x and !y) { cout << 0 << endl; return 0; }
    cout << min(x,y)+1 << endl;
    for(int i = 0; i <= min(x,y); i++) cout << i << " " << y-i << endl;
    return 0;
}

