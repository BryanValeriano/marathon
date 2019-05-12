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

unordered_map<int,int> bag;

int main() {
    ios::sync_with_stdio(false);
    int n,m,x;
    cin >> n >> m;
    while(n or m) {
        bag.clear();
        int ans = 0;
        for(int i = 0; i < n+m; i++) { 
            cin >> x;
            bag[x]++;
            if(bag[x] == 2) ans++;
        }
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}

