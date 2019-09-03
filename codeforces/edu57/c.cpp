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
    int x, q;
    cin >> q;
    while(q--) {
        cin >> x;
        bool flag = true;
        for(int i = 3; i <= 180; i++) {
            if(360 % i != 0) continue;
            int lado = 360/i;
            if(lado == x) { cout << i << endl; flag = false; break; }
            if(lado < x and lado % (x % lado) == 0) { cout << i << endl; flag = false; break; }
        }
        if(flag) cout << -1 << endl; 
    }
    return 0;
}

