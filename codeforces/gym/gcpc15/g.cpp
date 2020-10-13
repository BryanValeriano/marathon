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

    int n;
    cin >> n;
    vector<int> a(n);
    string ans = "yes";
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) if (a[i] < a[i - 1]) {
        ans = "no";
        break;
    }
    cout << ans << endl;
    return 0;
}

