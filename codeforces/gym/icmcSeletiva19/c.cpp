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

const int T = 2e3 + 2;
int dot[T][T];
int ori[T][T];
vector<int> ve;
vector<int> ve2;
map<int,int> bag;
map<int,int> bag2;
vii v;
int n, mx,my;

int binI(int x, int y) {
    int l = x;
    int r = mx;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(dot[mid][y] - dot[x-1][y] - dot[mid][y-1] + dot[x-1][y-1] >= 2) r = mid-1;
        else l = mid+1;
    }

    return l;
}

int binJ(int i, int k, int j) {
    int l = j;
    int r = my;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(dot[k][mid] - dot[i-1][mid] - dot[k][j-1] + dot[i-1][j-1] >= 4) r = mid-1;
        else l = mid+1;
    }

    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        v.eb(a,b);
        ve.pb(a);
        ve2.pb(b);
    }

    sort(ve.begin(), ve.end());
    sort(ve2.begin(), ve2.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    ve2.resize(unique(ve2.begin(), ve2.end()) - ve2.begin());
    for(int i = 0; i < ve.size(); i++) bag[ve[i]] = i+1;
    for(int i = 0; i < ve2.size(); i++) bag2[ve2[i]] = i+1;

    for(int i = 0; i < n; i++) {
        mx = max(mx,bag[v[i].fi]);
        my = max(my, bag2[v[i].se]);
        dot[bag[v[i].fi]][bag2[v[i].se]] = 1;
        ori[bag[v[i].fi]][bag2[v[i].se]] = 1;
    }

    for(int i = 1; i <= mx; i++)
        for(int j = 1; j <= my; j++)
            dot[i][j] += dot[i-1][j] + dot[i][j-1] - dot[i-1][j-1];

    int ans = 0;

    for(int i = 1; i <= mx; i++) {
        for(int j = 1; j <= my; j++) { 
            if(!ori[i][j]) continue;
            int k = binI(i,j);
            if(!ori[k][j]) continue;
            int p = binJ(i,k,j);
            if(!ori[i][p]) continue;
            if(!ori[k][p]) continue;
            if(dot[k][p] - dot[i-1][p] - dot[k][j-1] + dot[i-1][j-1] == 4) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

