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

int main() {
    ios_base::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());

    int n = s.size();
    vector<char> ans(n);
    int l = 0, r = 0;
    int a = 0;
    int b = n-1;

    for(int i = 0; i < s.size(); i++) {
        if(i&1) {
            if(t[r] >= s[l]) ans[a++] = t[r++];
            else ans[b--] = t[r++];
        } else {
            if(s[l] <= t[r]) ans[a++] = s[l++];
            else ans[b--] = s[l++];
        }
    }

    for(auto x : ans) cout << x;
    cout << endl;

    return 0;
}

