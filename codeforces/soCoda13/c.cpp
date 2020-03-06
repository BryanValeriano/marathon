#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
string s,t;

bool solve(int l1, int r1, int l2, int r2) {
    bool ok = 1;
    for(int i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
        ok &= (s[i] == t[j]);

    if(ok) return 1;
    if((r1-l1+1)&1) return 0;

    int mid1 = (l1+r1) >> 1;
    int mid2 = (l2+r2) >> 1;

    return ((solve(l1,mid1,l2,mid2) && solve(mid1+1,r1,mid2+1,r2)) or
            (solve(l1,mid1,mid2+1,r2) && solve(mid1+1,r1,l2,mid2)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    int n = s.size()-1;
    cout << (solve(0,n,0,n)? "YES" : "NO") << endl;
    return 0;
}

