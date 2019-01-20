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

int tent(int sum) {
    int moves = 0;
    if(sum & 1) { 
        sum -= 3;
        moves++;
        moves += sum/2;
    } else moves += sum/2;
    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int tot; cin >> tot;
        cout << tent(tot) << endl;
    }
    return 0;
}

