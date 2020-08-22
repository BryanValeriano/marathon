#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

    int n;
    cin >> n;
    if (n < 3) {
        cout << n + 1 << endl;
        return 0;
    }
    vector<double> acc(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        acc[i] = acc[i - 1] + log2(i);
    }
    double logn = log2(n);
    for (int i = 1;i <= n;i++) {
        if (1 + acc[n] < acc[n - i] + i * logn) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

