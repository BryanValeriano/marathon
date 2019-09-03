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
    int x; cin >> x;
    for(int a = 1; a <= x; a++)
        for(int b = 1; b <= x; b++) {
            if(a % b == 0 and a*b > x and a/b < x) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    cout << -1 << endl;
    return 0;
}

