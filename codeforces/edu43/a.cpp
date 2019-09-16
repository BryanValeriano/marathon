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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    string ans = "1";
    cin >> n;
    cin >> s;
    for(int i = 1; i < n; i++) if(s[i] == '0') ans += s[i];
    if(s == "0") { cout << '0' << endl; return 0; }
    cout << ans << endl;
    return 0;
}

