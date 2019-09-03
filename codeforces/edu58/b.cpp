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

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    string ans;
    int atual = 0;
    while(atual < (int)s.size() and s[atual] != '[') atual++;
    if(atual < (int)s.size()) {
        ans += s[atual];
        int abre = atual;
        atual++;
        int last = -1;
        while(atual < (int)s.size()) {
            if(s[atual] == ']') last = atual;
            atual++;
        }
        if(last == -1) { cout << -1 << endl; return 0; }
        for(int i = abre; i <= last; i++) {
            if(s[i] == ':' or s[i] == '|') ans += s[i];
        }
        ans += s[last];
        bool prim = false;
        int primeiro = INF;
        int seco = INF;
        for(int i = 0; i < (int)ans.size(); i++) {
            if(ans[i] == ':' and prim == false) { 
                primeiro = i;
                prim = true;
            }
            if(ans[i] == ':') seco = i;
        }
        if(primeiro == INF or seco == INF or primeiro == seco) { cout << -1 << endl; return 0; }
        string ans2;
        for(int i = 0; i < (int)ans.size(); i++) {
            if(ans[i] == ':' and i != primeiro and i != seco) continue;
            if(ans[i] == '|' and (i < primeiro or i > seco)) continue;
            else ans2 += ans[i];
        }
        cout << (int)ans2.size() << endl;
    } else cout << -1 << endl;

    return 0;
}

