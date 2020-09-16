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

    string s;
    cin >> s;
    string ans = "";
    map<char, int> cnt;
    map<char, char> counter = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
    for (int i = 0, j = 0;s[j];j++) {
        cnt[s[j]]++;
        ans += counter[s[j]];
        if (j - i + 1 == 3) {
            bool c = cnt.size() == 3;
            for (auto p : cnt) if (p.second != 1) c = false;
            if (c) {
                for (int k = 0;k < 3;k++) ans.pop_back();
                ans += 'C';
                cnt.clear();
                i = j + 1;
            }
            else if (cnt[s[i]]) cnt[s[i++]]--;
        }
    }
    cout << ans << endl;
    return 0;
}

