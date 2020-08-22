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

vii turns;
vii blocks;
string s;

char inv(char x) {
    if(x == 'U') return 'D';
    if(x == 'D') return 'U';
    if(x == 'R') return 'L';
    return 'R';
}

ii anda(int x, int y, char mov, int round) {
    y += (1<<round) * (mov == 'U'? 1 : mov == 'D' ? -1 : 0);
    x += (1<<round) * (mov == 'R'? 1 : mov == 'L' ? -1 : 0);
    return mk(x,y);
}

void bota(int x, int y, char mov) {
    blocks.eb(x + (mov == 'R'? 1 : mov == 'L' ? -1 : 0), y + (mov == 'U'? 1 : mov == 'D' ? -1 : 0));
}

bool hasBlock(int x, int y) {
    for(ii z : blocks)
        if(z.fi == x and z.se == y) return true;

    return false;
}

bool ok() {
    int x,y;
    for(int i = 0; i < (int)turns.size()-1; i++) {
        int xx,yy;
        tie(x,y) = turns[i];
        tie(xx,yy) = turns[i+1];
        while(x != xx or y != yy) {
            if(hasBlock(x,y)) return false;
            if(!x and !y) return false;
            x += (s[i] == 'R'? 1 : s[i] == 'L' ? -1 : 0);
            y += (s[i] == 'U'? 1 : s[i] == 'D' ? -1 : 0);
        }
        if(hasBlock(x,y)) return false;
    }
    return (!x and !y);
}

bool cancel(int x, int y) {
    if(x == 'U' and y == 'D') return true;
    if(x == 'D' and y == 'U') return true;
    if(x == 'L' and y == 'R') return true;
    if(x == 'R' and y == 'L') return true;
    return false;
}

bool hasCorn() {
    int del = -1;

    for(int i = 3; i < s.size(); i++) {
        if(cancel(s[i-1],s[i]) and s[i-1] == s[i-3] and s[i] == s[i-2]) {
            del = i;
            break;
        }
    }

    string t;
    for(int i = 0; i < s.size(); i++)
        if(i != del and i != del-1)
            t += s[i];

    s = t;
    return (del >= 3);
}

bool hasCorn2() {
    int del = -3;

    for(int i = 1; i < (int)s.size(); i++) {
        if(cancel(s[i-1],s[i])) {
            del = i;
            break;
        }
    }

    string t;
    for(int i = 0; i < s.size(); i++)
        if(i != del-1) t += s[i];

    s = t;
    return (del >= 1);
}

bool wtf() {
    if(s.size() < 3) return false;
    char x,y,z;
    z = s[s.size()-1];
    y = s[s.size()-2];
    x = s[s.size()-3];

    if(x != z) return false;

    if(x == 'L' and y == 'R') return true;
    if(x == 'R' and y == 'L') return true;
    if(x == 'U' and y == 'D') return true;
    if(x == 'D' and y == 'U') return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int x = 0, y = 0;
    turns.eb(x,y);

    if(wtf()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while(hasCorn()) continue;
    while(hasCorn2()) continue;

    for(int i = (int)s.size()-2; i >= 0; i--) {
        tie(x,y) = anda(x,y,inv(s[i+1]),i+1);
        turns.eb(x,y);
        bota(x,y,s[i]);
    }

    tie(x,y) = anda(x,y,inv(s[0]),0);
    turns.eb(x,y);
    reverse(turns.begin(),turns.end());

    if(ok()) {
        cout << x << " " << y << endl;
        cout << blocks.size() << endl;
        for(ii z : blocks) cout << z.fi << " " << z.se << endl;
    } else cout << "IMPOSSIBLE\n";

    return 0;
}

