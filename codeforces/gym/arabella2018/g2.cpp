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
const int T = 502;
map<int,int> bag[4];
int mat[T][T];
int n,m,l,u,ans;

void reset() {
    for(int i = 0; i < 4; i++) bag[i].clear();
    ans = INF;
}

void updateAns() {
    int a = INF;
    int b = 0;
    //cout << " ---- " << u << " " << l << endl;
    for(int i = 0; i < 4; i++) {
        a = min(a,bag[i].rbegin()->fi);
        b = max(b,bag[i].rbegin()->fi);
        //cout << *bag[i].begin() << " " << *bag[i].rbegin() << endl;
    }
    ans = min(ans,b-a);
}

void read() {
    cin >> n >> m;
    l = 1, u = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(i < u) {
                if(j < l) bag[0][mat[i][j]]++;
                else if(j > l) bag[1][mat[i][j]]++;
            } else if(i > u){
                if(j < l) bag[2][mat[i][j]]++;
                else if(j > l) bag[3][mat[i][j]]++;
            }
        }
    }
    updateAns();
}

void solve() {
    while(l+1 < m) {

        int cont = (l&1? 1 : -1);
        //cout <<  " aaaaa " << ((cont < 0 && u+cont > 0) || (cont > 0 && u+2*cont < n)) << endl;

        while((cont < 0 && u+cont > 0) || (cont > 0 && u+2*cont < n)) {
            u += cont;
            for(int j = 0; j < m; j++) {
                if(cont > 0) {
                    if(j < l) {
                        bag[0][mat[u-1][j]]++;
                        bag[2][mat[u][j]]--;
                        if(bag[2][mat[u][j]] == 0) bag[2].erase(mat[u][j]);
                    } else if(j > l) {
                        bag[1][mat[u-1][j]]++;
                        bag[3][mat[u][j]]--;
                        if(bag[3][mat[u][j]] == 0) bag[3].erase(mat[u][j]);
                    }
                } else {
                    if(j < l) {
                        bag[2][mat[u+1][j]]++;
                        bag[0][mat[u][j]]--;
                        if(bag[0][mat[u][j]] == 0) bag[0].erase(mat[u][j]);
                    } else if(j > l) {
                        bag[3][mat[u+1][j]]++;
                        bag[1][mat[u][j]]--;
                        if(bag[1][mat[u][j]] == 0) bag[1].erase(mat[u][j]);
                    }
                }
            }
            updateAns();
        }

        l++;
        if(l+1 >= m) break;
        for(int i = 0; i < n; i++) {
            if(i < u) {
                bag[0][mat[i][l-1]]++;
                bag[1][mat[i][l]]--;
                if(bag[1][mat[i][l]] == 0) bag[1].erase(mat[i][l]);
            } else if(i > u) {
                bag[2][mat[i][l-1]]++;
                bag[3][mat[i][l]]--;
                if(bag[3][mat[i][l]] == 0) bag[3].erase(mat[i][l]);
            }
        }
        updateAns();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        reset();
        read();
        solve();
        cout << ans << endl;
    }
    return 0;
}

