#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
vector< pair<int,int> > row;
const int MAX = 5e6;
int dp[MAX];

int bk(int s, int pos) {
    if(pos > row.size()) return 0;
    if(dp[s] != -1) return dp[s];
    int R = 0;
    if(s - row[pos].fi >= 0) { 
        R = bk(s - row[pos].fi, pos + 1) + row[pos].sec;
    }
    int L = bk(s, pos + 1);

    return dp[s] = max(R, L);

}

/*bool cmp(const pair<int,int>&i, const pair<int,int>&j) {
    return i.second < j.second;
}*/

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    while(n--) {
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            row.pb(mk(tmp1,tmp2));
        }
        //sort(row.begin(), row.end(), cmp);
        int s; cin >> s;
        memset(dp, -1, sizeof dp);
        cout << bk(s, 0) << endl;
        row.clear();
    }

    return 0;
}

