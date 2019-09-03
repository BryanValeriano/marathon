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

const int T = 2e5 + 10;

string t;
string s;
int erow[3][T];
int n,k;

int solve(int ini) {
    for(int i = 0; i < n; i++) erow[ini][i] = 0;

    for(int i = 0; i < n; i++) {
        erow[ini][i] = (s[i] != t[i+ini]);
        if(i > 0) erow[ini][i] += erow[ini][i-1];
        //cout << s[i] << " " << t[i+ini] << endl;
    }

    //for(int i = 0; i < n; i++) cout << erow[ini][i] << " ";
    //cout << endl;

    int ans = INF;

    for(int i = k-1; i < n; i++) 
        ans = min(ans, erow[ini][i] - (i-k >= 0? erow[ini][i-k] : 0));

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    int q; cin >> q;

    while(t.size() < T) t += "RGB";
    
    while(q--) {
        cin >> n >> k >> s;
        int ans = INF;
        for(int i = 0; i < 3; i++) ans = min(ans, solve(i));
        cout << ans << endl;
    }

    return 0;
}

