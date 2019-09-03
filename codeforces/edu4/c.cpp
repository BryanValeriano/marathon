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

const int T = 1e6 + 10;
char stk[T];

int main() {
    ios::sync_with_stdio(false);
    int iter = 0;
    int ans = 0;
    while(cin >> stk[++iter]) {
        if(stk[iter] == '>') { 
            iter--;
            if(stk[iter] != '<') 
                ans++;
            iter--;
        }
        if(stk[iter] == ')') { 
            iter--;
            if(stk[iter] != '(') 
                ans++;
            iter--;
        }
        if(stk[iter] == '}') { 
            iter--;
            if(stk[iter] != '{') 
                ans++;
            iter--;
        }
        if(stk[iter] == ']') { 
            iter--;
            if(stk[iter] != '[') 
                ans++;
            iter--;
        }
        if(iter < 0) { cout << "Impossible" << endl; return 0; }
    }
    if(iter == 1) cout << ans << endl;
    else cout << "Impossible" << endl;
    return 0;
}

