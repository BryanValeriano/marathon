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

const int T = 503;
bool mat[T][T];
int maxi[T];
int n,m;
multiset<int> maxs;

int search(int x) {
    int ans = 0;
    int at = 0;

    for(int i = 0; i < m; i++) {
        if(mat[x][i]) at++;
        else {
            ans = max(ans,at);
            at = 0;
        }
    }

    return max(ans,at);
}

int main() {
    ios::sync_with_stdio(false);
    int q,x,y;
    cin >> n >> m >> q;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    for(int i = 0; i < n; i++) {
        maxi[i] = search(i);
        maxs.insert(maxi[i]);
    }

    while(q--) {
        cin >> x >> y;
        x--; y--;
        mat[x][y] = !mat[x][y];
        maxs.erase(maxs.find(maxi[x]));
        maxi[x] = search(x);
        maxs.insert(maxi[x]);
        cout << *maxs.rbegin() << endl;
    }

    return 0;
}

