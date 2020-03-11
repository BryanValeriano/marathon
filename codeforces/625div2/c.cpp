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

int solve(string s) {
    string x;

    int best = -1;
    int pos = -1;

    for(int i = 1; i < s.size()-1; i++) {
        if(s[i]-s[i-1] == 1 or s[i]-s[i+1] == 1)
            if(best < s[i]-'a') best = s[i]-'a', pos = i;
    }

    if(best == -1) return 0;

    for(int i = 0; i < s.size(); i++) {
        if(i == pos) continue;
        x += s[i];
    }

    return solve(x) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    s = '#' + s + '#';
    cout << solve(s) << endl;
    return 0;
}

