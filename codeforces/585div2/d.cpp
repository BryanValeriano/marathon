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

void bic() {
    cout << "Bicarp" << endl;
    exit(0);
}

void mon() {
    cout << "Monocarp" << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int m1 = 0, m2 = 0;
    int b1 = 0, b2 = 0;
    int um = 0, dois = 0;
    bool turn = 0;

    for(int i = 1; i <= n; i++) {
        char x; cin >> x;
        if(x == '?') {
            if(turn) {
                if(i <= n/2) b1 += 9;
                else b2 += 9;
            } else {
                if(i <= n/2) m1 += 9;
                else m2 += 9;
            }
            turn = !turn;
        } else {
            if(i <= n/2) um += (x-'0');
            else dois += (x-'0');
        }
    }

    for(int i = 0; i < 4; i++) {
        int x = um;
        int y = dois;

        if(i&1) x += b1;
        if(i&2) y += b2;

        if(x < y and y-x > m1) mon();
        if(x > y and x-y > m2) mon();
    }

    bic();
    
    return 0;
}

