#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int q; cin >> q;
    int x,y;
    while(q--) {
        cin >> x >> y;
        int ans = n/max(x,y);
        if(n % max(x,y) >= min(x,y)) ans++;
        cout << ans << endl;
    }
}
