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
    double n, p; cin >> n >> p;
    vector<string> oper;
    string s;
    double qtd = 0;
    double ans = 1;
    for(int i = 0; i < n; i++) {
        cin >> s;
        oper.pb(s);
        if(s == "halfplus") qtd += 0.5;
    }
    reverse(oper.begin(), oper.end()); 
    for(int i = 1; i < n; i++) {
        if(oper[i] == "half") ans = (ans + ans);
        else ans = (ans + ans + 1);
    }
    cout << fixed << setprecision(0) << (ans - qtd)*p << endl;
}
