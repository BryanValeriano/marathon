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

const int T = 15;
int tot;
int fora;

int solve(int at, int out, int mask) {
    if(out > fora) return 0;
    if(at > tot) return (out <= fora);

    int ans = 0;

    for(int i = 1; i <= tot; i++) 
        if(!(mask & (1 << i))) ans += solve(at + 1,out + (i != at), mask | (1 << i));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    for(tot = 4; tot <= T; tot++)
        for(fora = 1; fora <= 4; fora++)
            cout << tot << " " << fora << " " << solve(1,0,0) << endl;
    

    return 0;
}

