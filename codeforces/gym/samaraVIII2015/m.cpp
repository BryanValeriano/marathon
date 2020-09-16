#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int q; cin >> q;
    int x,y;
    while(q--) {
        cin >> x >> y;
        if(x < y) swap(x,y);
        int ans = n/x;
        if(n%x >= y) ans++;
        cout << ans << endl;
    }
}
