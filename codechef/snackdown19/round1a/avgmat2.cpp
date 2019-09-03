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
ll manhattan[2*T];
int n, m;

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

int main() {
    int tc; scanf("%d\n", &tc);
    while(tc--) {
        memset(manhattan,'\0', sizeof manhattan);
        scanf("%d %d\n", &n, &m);
        for(int i = 1; i <= n + m - 2; i++) resp[i] = 0;
        char aux;
        vii track;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%c ", &aux);
                if(aux == '1') track.eb(i,j); 
            }
        }
        for(auto x : track)
            cout << x.fi << " " << x.se << endl;
        sort(track.begin(), track.end());
        for(int i = 0; i < track.size(); i++) {
            for(int j = 1; j <= n + m -2; j++) { 
                int l = 0;
                int h = 0;
                l = upper_bound(track.begin(), track.end(), ii(track[i].fi + (j-1), 0), cmp) - track.begin(); 
                h = upper_bound(track.begin(), track.end(), ii(track[i].fi + j, 0), cmp) - track.begin(); 
                cout << track[i].fi << " " << track[i].se << " " << j << " " << h-l << endl;
                resp[j] += h - l;
            }
        }
        for(int i = 1; i <= n + m - 2; i++) 
            printf("%d ", resp[i]);
        printf("\n");
    }
    return 0;
}

