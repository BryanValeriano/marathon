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

    int n, d, w;
    cin >> n >> d >> w;
    vector<string> ss(n);
    for (int i = 0;i < n;i++) cin >> ss[i];
    int ans = 1, len = 0, word = 0;
    bool first = true;
    if (n & 1) ss[n - 1] += ' ';
    for (int i = 0;i < n;i++) {
        int l, r, del;
        if (i & 1) l = ss[i].length() - 1, r = -1, del = -1;
        else l = 0, r = ss[i].length(), del = 1;
        for (int j = l;j != r;j += del) {
            if (isalpha(ss[i][j])) {
                word++;
            }
            else {
                if (len + word + !first > w) {
                    ans++;
                    len = word;
                }
                else len += word + !first;
                first = false;
                word = 0;
                if (ss[i][j] != '.') break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

