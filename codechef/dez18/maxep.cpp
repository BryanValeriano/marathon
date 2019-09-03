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
    ios_base::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    int last = 0;
    int x;
    int ini = 1;
    for(int i = 1000; i >= 1; i /= 10) {
        if(last == 1) { cout << 2 << endl << flush; last = 0; } 
        if(i == 100) continue;
        for(x = ini; x <= n; x += i) {
            cout << 1 << " " << x << endl << flush;
            cin >> last;
            if(last == 1) {
                if(i == 1) { cout << 3 << " " << x << endl << flush; return 0; }
                else { ini = max(1, x - i); break; }
            }
        }
        if(last == 1 and i == 1) { cout << 3 << " " << n << endl << flush; return 0; }
        if(last == 0) ini = max(1, x - i);
    }
    return 0;
}

