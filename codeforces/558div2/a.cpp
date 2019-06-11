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

const int T = 1e3 + 5;
bool v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if(!m) { cout << 1 << endl; return 0; }
    cout << min(n-m, m) << endl;
    return 0;
}

