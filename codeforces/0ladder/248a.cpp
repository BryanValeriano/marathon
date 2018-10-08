#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a = 0;
    int b = 0;
    int x1, x2;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        if(x1)a++;
        if(x2)b++;
    }
    cout << min(n-a, a) + min(n-b, b) << endl;
    return 0;
}

