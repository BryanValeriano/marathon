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
const ll MOD =11092019;
const int T = 30;
ll freq[T];

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++)
        freq[s[i]-'a']++;

    ll ans = 1;
    for(int i = 0; i < T; i++)
        ans = (ans*(freq[i]+1))%MOD;

    cout << ans << endl;

    return 0;
}

