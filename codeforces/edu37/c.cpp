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

const int T = 2e5 + 2;
int v[T];
string s;
int n;

void solve() {
    vector<int> tmp;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') tmp.pb(v[i]);
        else if(tmp.size()) {
            tmp.pb(v[i]);
            sort(tmp.begin(), tmp.end());
            int at = i;
            while(tmp.size()) v[at--] = tmp.back(), tmp.pop_back();
        }
    }

    if(tmp.size()) {
        sort(tmp.begin(), tmp.end());
        int at = n-1;
        while(tmp.size()) v[at--] = tmp.back(), tmp.pop_back();
    }
}

bool check() {
    for(int i = 0; i < n; i++) if(v[i] != i+1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> s; s += "0";
    
    solve();
    cout << (check()? "YES" : "NO") << endl;
    return 0;
}

