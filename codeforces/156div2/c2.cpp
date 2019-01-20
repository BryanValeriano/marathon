#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int T = 4e3 + 10;
const int N = 1e6 + 10;
vector<int> track[N];
int v[T];
bool dp[T][T];

int acha(int i, int j) {
    int x = v[i];
    int y = v[j];
    int ans = 2;
    
    int round = 3;
    while(true) {
        if(dp[i][j]) break;
        dp[i][j] = true;
        if(round & 1) {
            i = lower_bound(track[x].begin(), track[x].end(), j+1) - track[x].begin();
            if(i < track[x].size()) i = track[x][i];
            else break;
        }
        else {
            j = lower_bound(track[y].begin(), track[y].end(), i+1) - track[y].begin();
            if(j < track[y].size()) j = track[y][j];
            else break;
        }
        round++;
    }
    return round - 1;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        track[v[i]].pb(i);
    }

    for(int i = 0; i <= N; i++) sort(track[i].begin(), track[i].end());
    int ans = 1;

    for(int i = 0; i < n; i++) 
        for(int j = i+1; j < n; j++)
                ans = max(ans, acha(i,j));
        


    cout << ans << endl;
    return 0;
}

