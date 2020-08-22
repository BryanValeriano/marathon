#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    string msg = b;
    for (int i = 0;i < n;i++) msg[m - i - 1] = a[n - i - 1];
    for (int i = m - n - 1;i >= 0;i--) {
        msg[i] = (b[i + n] - msg[i + n] + 26) % 26 + 'a';
    }
    cout << msg << endl;
    return 0;
}

