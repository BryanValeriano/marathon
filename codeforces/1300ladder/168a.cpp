#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    double n, x, y; cin >> n >> x >> y;
    double need = (n* y/(100));
    need = ceil(need)- x;
    double zero = 0;
    double tmp = max(zero, need);
    cout << tmp << endl;
    return 0;
}
