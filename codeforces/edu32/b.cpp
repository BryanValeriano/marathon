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
    int n; cin >> n;
    int x = 0;
    int y = 0;
    char s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == 'U') y++;
        else if(s == 'D') y--;
        else if(s == 'L') x--;
        else x++;
    }
    cout << n - (abs(x) + abs(y)) << endl;

    return 0;
}

