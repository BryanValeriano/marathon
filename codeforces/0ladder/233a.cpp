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
    if(n&1) { cout << -1 << endl; return 0; }
    for(int i = 1; i <= n; i++) 
        cout << (i&1? i + 1 : i - 1) << " ";
    cout << endl;

    return 0;
}

