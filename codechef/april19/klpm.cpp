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

unordered_map<string, ll> id;
set< pair<string,string> > vis;

void rem(string x) {
    string y = "";
    for(int i = 0; i < x.size(); i++) {
        y += x[i];
        id[y]--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        string x = "";
        for(int j = i; j < n; j++) {
            x += s[j];
            id[x]++;
        }
    }


    ll ans = 0;

    for(auto z : id) {
        string at = z.fi;
        string rev = z.fi;
        ll qtd = z.se;
        rem(at);

        string x = "";
        if(!(at.size() & 1)) x = z.fi[0];
        reverse(rev.begin(), rev.end());

        if(rev == at) ans += id[at];
        else ans += qtd * id[rev];

        if(x != at and x != rev) ans += qtd * id[x];
    }

    cout << ans << endl;

    return 0;
}

