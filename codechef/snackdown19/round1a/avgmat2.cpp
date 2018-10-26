#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 305;
int resp[2*T];
int n, m;

int main() {
    int tc; scanf("%d\n", &tc);
    while(tc--) {
        scanf("%d %d\n", &n, &m);
        for(int i = 1; i <= n + m - 2; i++) resp[i] = 0;
        vii track; 
        char aux;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%c ", &aux);
                if(aux == '1') track.eb(i,j);
            }
        }
        for(int i = 0; i < track.size(); i++) { 
            for(int j = i + 1; j < track.size(); j++) {
                int d = 0;
                d += abs(track[i].fi - track[j].fi);
                d += abs(track[i].se - track[j].se);
                resp[d]++;
            }
        }
        for(int i = 1; i <= n + m - 2; i++) 
            printf("%d ", resp[i]);
        printf("\n");
    }
    return 0;
}

