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

int fst[30];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s;

    for(int i = 0; i < n; i++) {
        cin >> s;
        fst[s[0]-'a']++;
    }

    int ans = 0;

    for(int i = 0; i < 26; i++) {
        int a = fst[i]/2;
        int b = fst[i]/2 + (fst[i]&1);

        ans += (a*(a-1))/2 + (b*(b-1))/2;
    }

    cout << ans << endl;

    return 0;
}

