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

const int T = 1e5 + 5;

int p[T];
int l[T];
vector<vector<int> > ans;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < m; i++) cin >> l[i];

    int i = 0, j = 0;
    
    while(i < n and j < m) {
        vector<int> tmp;
        while(i < n and j < m and p[i] == l[j]) {
            if(tmp.size() == k) {
                ans.pb(tmp);
                tmp.clear();
            }
            tmp.pb(i+1);
            i++, j++;
        }
        if(tmp.size()) ans.pb(tmp);
        j++;
    }
            
    cout << ans.size() << endl; 
    for(auto z : ans) {
        cout << z.size() << " ";
        for(auto y : z) cout << y << " ";
        cout << endl;
    }
    
    return 0;
}

