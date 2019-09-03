#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5;
int row[T];
 
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cin >> row[0];
        int swp = 0;
        int eq = 0;
        for(int i = 1; i < n; i++) { 
            cin >> row[i];
            if(row[i] < row[i-1]) swp++;
            if(row[i] == row[i-1]) eq++;
        }
        if(swp == 0){ cout << "YES" << endl; continue; }
        cout << (((swp > 1 and eq != n-1) or row[0] < row[n-1])? "NO" : "YES") << endl;
    }
    return 0;
}

