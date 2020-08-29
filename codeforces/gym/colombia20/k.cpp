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
string x[2];
string y[2];

bool isChar(char a) {
    return (a >= 'a' and a <= 'z');
}

void cut(string s, int op) {
    int ok = 0;
    while(isChar(s[ok])) x[op] += s[ok++];
    while(ok < s.size()) y[op] += s[ok++];
}

int main() {
    ios_base::sync_with_stdio(false);
    string s,t; cin >> s >> t;
    cut(s, 0);
    cut(t, 1);
    cout << (x[0] < x[1]? '<' : x[0] > x[1]? '>' : y[0].size() < y[1].size()? '<' : y[0].size() > y[1].size()? '>' : y[0] < y[1]? '<' : y[0] > y[1]? '>' : '=') << endl;

    return 0;
}

