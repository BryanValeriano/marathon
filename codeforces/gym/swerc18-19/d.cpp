#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int32_t main() {
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    int m;
    cin >> m;
    vector<int> maxY(x,0);
    vector<int> minY(x,INF);
    vector<int> mini(y,0);
    vector<int> maxi(y,0);
    vector<bool> vis(x,0);

    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        maxY[a] = max(maxY[a],b);
        minY[a] = min(minY[a],b);
        vis[a] = 1;
    }

    ll ans = INF;
    ll tmp = 0;

    for(int i = 0; i < x; i++) {
        if(!vis[i]) continue;
        mini[minY[i]]++;
        maxi[maxY[i]]++;
        tmp += maxY[i];
    }

    ans = tmp;

    for(int i = 1; i < y; i++) maxi[i] += maxi[i-1];
    for(int i = y-2; i >= 0; i--) mini[i] += mini[i+1];

    for(int i = 1; i < y; i++) {
        tmp -= mini[i];
        tmp += maxi[i-1];
        ans = min(tmp,ans);
    }

    cout << (2*ans+x-1) << endl;
    return 0;
}

