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
const int T = 2e3+2;
bool dp[T][T];
bool vis[T][T];
int choose[T][T];
int cost[10][T];
string v[T];
string nums[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n,k;

int hamming(int num, int pos) {
    int ans = 0;
    for(int i = 0; i < 7; i++) {
        ans += (nums[num][i] != v[pos][i]);
        if(v[pos][i] == '1' and nums[num][i] == '0') return INF;
    }
    return ans;
}

int solve(int at, int t) {
    if(at == n) return (t==0?1:0);
    if(vis[at][t]) return dp[at][t];

    vis[at][t] = 1;
    for(int i = 9; i >= 0; i--) {
        int c = cost[i][at];
        if(c <= t) {
            bool ok = solve(at+1, t-c);
            if(ok) {
                choose[at][t] = i;
                dp[at][t] = 1;
                return dp[at][t];
            }
        }
    }

    return dp[at][t] = 0;
}

void build(int at, int t) {
    if(at==n) {cout << endl; return;}
    cout << choose[at][t];
    int c = cost[choose[at][t]][at];
    build(at+1,t-c);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int j = 0; j < 10; j++) {
            cost[j][i] = hamming(j,i);
        }
    }

    if(solve(0,k)) build(0,k);
    else cout << -1 << endl;
    return 0;
}

