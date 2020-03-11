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
const int T = 1e6 + 2;
stack<int> open;
int c[T];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    memset(c, -1, sizeof c);
    cin >> s;
    int ans = 0;
    int qtd = 1;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') open.push(i);
        else {
            if(open.empty()) continue;
            int x = open.top();
            open.pop();
            c[i] = x;
        }
    }

    for(int i = 0; i < s.size(); i++) {
        if(~c[i]) {
            if(c[i]-1 >= 0 and (~c[c[i]-1])) c[i] = min(c[i], c[c[i]-1]);
            if(i-c[i]+1 > ans) ans = i-c[i]+1, qtd = 1;
            else if(i-c[i]+1 == ans) qtd++;
        }
    }

    cout << ans << " " << qtd << endl;

    return 0;
}

