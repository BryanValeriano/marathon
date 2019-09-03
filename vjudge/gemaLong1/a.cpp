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

const int T = 1e5 + 5;
int v[T][30];
string s,x;

void build() {
    memset(v, INF, sizeof v);
    s = "$" + s;

    for(int i = 1; i < s.size(); i++)
        v[i-1][s[i]-'A'] = i;
    
    for(int j = 0; j < 30; j++)
        for(int i = s.size()-1; i >= 0; i--)
            v[i][j] = min(v[i][j], v[i+1][j]);
    
}

bool search() {
    int pointer = 0;
    for(int i = 0; i < x.size(); i++) {
        if(pointer == INF) return false;
        pointer = v[pointer][x[i]-'A'];
    }
    return (pointer != INF);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    build();

    int q; cin >> q;
    int ans = 0;

    while(q--) {
        cin >> x;
        if(search()) ans++;
    }
    
    cout << ans << endl;

    return 0;
}

