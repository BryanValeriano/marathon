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
const int T = 2e5+5;
const int N = 30;
int v[N][T];

int main() {
    ios_base::sync_with_stdio(false);
    memset(v,INF,sizeof v);
    string s; cin >> s;
    s = "#" + s;
    for(int i = 1; i < s.size(); i++) v[s[i]-'a'][i-1] = i;

    for(int i = s.size()-1; i >= 0; i--)
        for(int j = 0; j < N; j++)
            v[j][i] = min(v[j][i],v[j][i+1]);

    int q;
    cin >> q;
    string t;
    string ans;
    int i = 0, pos;

    while(q--) {
        i = 0;
        ans = "";
        cin >> t;
        pos = v[t[i]-'a'][0];

        while(pos != INF) {
            ans += t[i++];
            if(i < t.size()) pos = v[t[i]-'a'][pos];
            else break;
        }

        cout << (ans.size()? ans : "IMPOSSIBLE") << endl;
    }

    return 0;
}

