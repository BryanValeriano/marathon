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

const int T = 30;
const int N = 2e5+5;

int best[T];
int ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;

    best[s[0]-'a'] = 1;
    ans[0] = 1;
    int col = 1;

    for(int i = 1; i < n; i++) {
        for(int j = s[i]-'a' + 1; j < T; j++)
            ans[i] = max(ans[i],best[j]+1);
        best[s[i]-'a'] = max(best[s[i]-'a'], ans[i]);
        col = max(col,ans[i]);
    }

    cout << col << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

