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
    int n, k;
    cin >> n >> k;

    if(k == 1) { cout << 1 << endl; return 0; }
    if(k == 2) {
        ll base = 7;
        ll step = 4;
        for(int i = 5; i <= n; i++) base += step, step++;
        cout << base << endl;
    }
    if(k == 3) {
        ll base = 15;
        ll step = 16;
        ll step2 = 9;
        for(int i = 5; i <= n; i++) base += step, step += step2, step2 += 2;
        cout << base << endl;
    }
    if(k == 4) {
        ll base = 24;
        ll step = 52;
        ll step2 = 63;
        ll step3 = 38;
        for(int i = 5; i <= n; i++) base += step, step += step2, step2 += step3, step3 += 9;
        cout << base << endl;
    }

    return 0;
}

