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

const int T = 1e4 + 100;
bool dp[T];
int v[105];

int main() {
    ios_base::sync_with_stdio(false);
    int x,y,n;
    cin >> x >> y >> n;
    int cont = 0;
    while(x or y or n) {
        cout << "Teste " << ++cont << endl;
        if(x < y) swap(x,y);
        int tot = 0;
        for(int i = 0; i < n; i++) cin >> v[i], tot += v[i];

        bool flag = 0;

        if(tot < x-y) flag = 1;
        tot -= x-y;
        if(tot & 1) flag = 1;
        int gol = 0;

        if(!flag) {
            gol = tot/2;
            for(int i = 0; i <= gol; i++) dp[i] = 0;
            dp[0] = 1;

            for(int i = 0; i < n; i++)
                for(int j = gol; j-v[i] >= 0; j--)
                    dp[j] = max(dp[j], dp[j-v[i]]);
        }

        cout << (dp[gol] and !flag? 'S' : 'N') << endl;
        cin >> x >> y >> n;
        if(x or y or n) cout << endl;
    }



    return 0;
}

