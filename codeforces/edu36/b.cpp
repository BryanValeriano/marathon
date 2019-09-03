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

int main() {
    ios::sync_with_stdio(false);
    int n,pos,l,r;
    cin >> n >> pos >> l >> r;

    int corner1 = (l == 1);
    int corner2 = (r == n);
    int npos = pos;

    int ans1 = 2 - corner1 - corner2;
    if(!corner1) ans1 += abs(pos-l), npos = l;
    if(!corner2) ans1 += abs(npos-r);

    int ans2 = 2 - corner1 - corner2;
    npos = pos;

    if(!corner2) ans2 += abs(pos-r), npos = r;
    if(!corner1) ans2 += abs(npos-l);

    cout << min(ans1,ans2) << endl;

    return 0;
}

