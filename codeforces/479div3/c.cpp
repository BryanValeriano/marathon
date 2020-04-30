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

int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int x = (k?v[k-1]:1);
    int ans = 0;
    for(int i = 0; i < n; i++) ans += (v[i] <= x);
    cout << (ans == k? x : -1) << endl;
    return 0;
}

