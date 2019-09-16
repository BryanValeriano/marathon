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

const int T = 1e3 + 2;

string ok = "BGR";
string s;
int r,g,b;

bool can(string x) {
    int f = -1;
    int l = INF;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == x[2]) l = i;
        if(s[i] == x[0] and f == -1) f = i;
    }

    for(int i = 0; i < s.size(); i++)
        if(s[i] == x[1] and i > f and i < l) return 0;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else b++;
    }

    do {
        if(can(ok)) {cout << "YES" << endl; return 0; }
    } while(next_permutation(ok.begin(), ok.end()));

    can("RBG");
    cout << "NO" << endl;

    return 0;
}

