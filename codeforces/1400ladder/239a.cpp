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
    int y,n,k;
    cin >> y >> k >> n;
    vector<int> ans;
   
    int first = k; 
    while((first < y or first % k != 0) and first <= n) first += k;

    for(int i = first - y; i + y <= n; i += k) 
        if(i != 0) ans.pb(i);

    if(ans.size() == 0) cout << -1; 
    else for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

