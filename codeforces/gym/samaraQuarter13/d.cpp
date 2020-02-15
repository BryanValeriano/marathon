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
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> a(3);
    for (int i = 0;i < 3;i++) cin >> a[i];
    string ans(n, ' ');
    for (int i = 0;i < n;i++) {
        char c = ' ';
        map<char, int> cnt;
        for (int j = 0;j < 3;j++) {
            cnt[a[j][i]]++;
            if (cnt[a[j][i]] > cnt[c]) c = a[j][i];
        }
        ans[i] = c;
    }
    cout << ans << endl;
    return 0;
}
