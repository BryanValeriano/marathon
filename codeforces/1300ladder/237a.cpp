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
map< pair<int,int>, int> id;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int h, m;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> h >> m;
        id[ii(h,m)]++;
        maxi = max(maxi, id[ii(h,m)]);
    }
    cout << maxi << endl;
    return 0;
}

