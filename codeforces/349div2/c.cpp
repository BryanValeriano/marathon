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
const int T = 1e4+2;
bool vis[T][2][2];
string s;
int n;
set<string> bag;

bool dif(int pos, int t) {
    string x,y;
    for(int i = pos; i < pos+t; i++) x += s[i];
    for(int i = pos+t; i < n and i < pos+t+t; i++) y += s[i];
    //cout << pos << " " << x << " " << y << endl;
    return (x != y);
}

void solve(int pos, bool pode2, bool pode3) {
    if(vis[pos][pode2][pode3]) return;
    vis[pos][pode2][pode3] = 1;

    int sobra = n-pos;
    string x;
    bool n2 = 0, n3 = 0;

    if(pode2 and ((sobra-2 > 1) or (sobra-2 == 0))) {
        if(sobra-2 == 4 and (!dif(po2+2,2))) continue;
        if(sobra-2 == 6 and (!dif(po2+2,3))) continue;
        n2 = dif(pos,2);
        x += s[pos];
        x += s[pos+1];
        bag.insert(x);
        solve(pos+2,n2,1);
    }
    x = "";

    if(pode3 and ((sobra-3 > 1) or (sobra-3 == 0))) {
        n3 = dif(pos,3);
        x += s[pos];
        x += s[pos+1];
        x += s[pos+2];
        bag.insert(x);
        solve(pos+3,1,n3);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();

    for(int i = 5; i < n; i++)
        solve(i,1,1);

    cout << bag.size() << endl;
    for(string x : bag) cout << x << endl;

    return 0;
}

