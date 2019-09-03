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
int n;
int v[5];
map<int,int> ans;

void gen(int x, int mask) {
    if(__builtin_popcount(mask) == 5) {
        ans[x] = mask;
        return;
    }

    for(int i = 0; i <= 9; i++) 
        if((mask & (1<<i)) == 0) 
            gen(x*10 + i, mask | (1<<i));
}


bool solve() {
    bool flag = false;
    for(auto x : ans) 
        if(x.fi % n == 0 and ans.count(x.fi/n)) 
            if(__builtin_popcount(x.se | ans[x.fi/n]) == __builtin_popcount(x.se) + __builtin_popcount(ans[x.fi/n])) {
                flag = true;
                cout << fixed << setw(5) << setfill('0') << x.fi;
                cout << " / "; 
                cout << fixed << setw(5) << setfill('0') << (x.fi/n);
                cout << " = " << n << endl;
            }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    gen(0,0);
    while(n) {
        if(!solve()) cout << "There are no solutions for " << n << "." << endl;
        cin >> n;
        if(n) cout << endl;
    }
    return 0;
}

