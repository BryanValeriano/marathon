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

const int T = 110;

int ini[T];
int fim[T];
set<string> names[T];
set<string> ans;

void overl(int i, int j) {
    for(auto x : names[i]) if(names[j].count(x)) ans.insert(x);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ans.clear();
        string lixo;
        for(int i = 0; i < n; i++) {
            names[i].clear();
            cin >> lixo;
            cin >> ini[i] >> fim[i];
            int k; cin >> k; 
            for(int j = 0; j < k; j++) {
                cin >> lixo;
                names[i].insert(lixo);
            }
        }
        for(int i = 0; i < n; i++) 
            for(int j = i+1; j < n; j++) { 
                if(max(ini[i],ini[j]) <= min(fim[i],fim[j]))
                    overl(i,j);
            }    

        cout << ans.size() << endl;
        for(auto x : ans) cout << x << endl;
    } 
    return 0;
}

