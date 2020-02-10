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
int a = 0, g = 0, c = 0, t = 0;

char min() {
    if(a <= g and a <= c and a <= t) { a++; return 'A'; }
    if(g <= a and g <= c and g <= t) { g++; return 'G'; }
    if(c <= g and c <= a and c <= t) { c++; return 'C'; }
    t++; return 'T';
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') a++;
        else if(s[i] == 'C') c++;
        else if(s[i] == 'G') g++;
        else if(s[i] == 'T') t++;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '?') s[i] = min();
    }

    if(a == c and c == g and g == t) cout << s << endl;
    else cout << "===" << endl;


    return 0;
}

