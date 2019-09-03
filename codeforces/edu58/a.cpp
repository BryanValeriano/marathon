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
    int q; cin >> q;
    int l,r,d;
    while(q--) {
        cin >> l >> r >> d;
        bool flag = true;
        for(int i = d; i < l; i += d) {
            cout << i << endl;
            flag = false;
            break;
        }
        if(flag) {
            if(d < 1e7) {
                for(int i = r+1; i <= 2e9; i++) {
                    if(i % d == 0) {
                        cout << i << endl;
                        break;
                    }
                }
            } else {
                for(int i = d; i <= 2e9; i += d) {
                    if(i > r) {
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

