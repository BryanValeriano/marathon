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

map<char,int> qtd;
map<char,bool> la;
map<char,bool> lb;
map<char,bool> ra;
map<char,bool> rb;

void pre() {
    qtd['0'] = 6; la['0'] = 1; lb['0'] = 1; ra['0'] = 1; rb['0'] = 1;
    qtd['1'] = 2; la['1'] = 0; lb['1'] = 0; ra['1'] = 0; rb['1'] = 0;
    qtd['2'] = 5; la['2'] = 1; lb['2'] = 0; ra['2'] = 0; rb['2'] = 1;
    qtd['3'] = 5; la['3'] = 1; lb['3'] = 1; ra['3'] = 0; rb['3'] = 0;
    qtd['4'] = 4; la['4'] = 1; lb['4'] = 1; ra['4'] = 1; rb['4'] = 0;
    qtd['5'] = 5; la['5'] = 0; lb['5'] = 1; ra['5'] = 1; rb['5'] = 0;
    qtd['6'] = 6; la['6'] = 0; lb['6'] = 1; ra['6'] = 1; rb['6'] = 1;
    qtd['7'] = 3; la['7'] = 1; lb['7'] = 1; ra['7'] = 0; rb['7'] = 0;
    qtd['8'] = 7; la['8'] = 1; lb['8'] = 1; ra['8'] = 1; rb['8'] = 1;
    qtd['9'] = 6; la['9'] = 1; lb['9'] = 1; ra['9'] = 1; rb['9'] = 0;
}

int solve(string s) {
    int ans = qtd[s[0]] + qtd[s[1]];
    int rest = 0;
    if((la[s[0]] && ra[s[1]]) && (lb[s[0]] && rb[s[1]])) rest = 2;
    else if((la[s[0]] && ra[s[1]]) && (lb[s[0]] == rb[s[1]])) rest = 1;
    else if((la[s[0]] == ra[s[1]]) && (lb[s[0]] && rb[s[1]])) rest = 1;
    return ans-rest;
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    int tc; cin >> tc;
    while(tc--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}

