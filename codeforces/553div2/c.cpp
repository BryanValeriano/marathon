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
    int ans = 0;
    int x = 11; 
    for(int i = 0; i < 16; i++) {
        ans += x;
        x += 2;
    }
    cout << ans << endl;
    return 0;
}

