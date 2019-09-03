#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int aux; cin >> aux;
        cout << (360 % (180-aux) == 0? "YES" : "NO") << endl;
    }
    return 0;
}

