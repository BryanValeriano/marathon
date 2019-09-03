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
const int T = 100 + 10;
int n;
int row[T];
int memo[T][4];

int dp(int atual, int last) {
    if(atual == n) return 0;
    int &r = memo[atual][last];
    if(r != -1) return r;
    int L = 0;
    int R = 0;
    if((last == 1 or last == 0) && (row[atual]== 2 or row[atual] == 3)) 
        L = max(L,dp(atual+1, 2) + 1);
    if((last == 2 or last == 0) && (row[atual] == 1 or row[atual] == 3)) 
        L = max(L,dp(atual+1, 1) + 1); 
   
    R = max(R, dp(atual+1, 0));

    return r = max(R,L);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(memo, -1, sizeof memo);
    for(int i = 0; i < n; i++) 
        cin >> row[i];
    cout << n - dp(0, 0) << endl;
    return 0;
}

