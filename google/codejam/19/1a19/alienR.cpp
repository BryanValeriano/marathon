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

const int T = 1e3 + 10;
string v[T];
bitset<T> vis;
unordered_set<string> bag;

int equal(string a, string b) {
    int ans = 0;
    for(int i = 0; i < min(a.size(),b.size()); i++) {
        if(a[i] == b[i]) ans++;
        else return ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int n; cin >> n;
        bag.clear();

        for(int i = 0; i < n; i++) { 
            cin >> v[i];
            reverse(v[i].begin(), v[i].end());
        }
        
        string a,b;
        int best = 0;
        int id = 0;

        for(int i = 0; i < n; i++) {
            a = v[i];
            best = 0;
            for(int j = i+1; j < n; j++) { 
                if(vis[j])
                int tent = equal(a,v[j]);

                if(tent > best) {
                    best = tent;
                    b = v[j];
                    id = j;
                }
            }

            string x = "";
            string y = x;
            for(int i = 0; i < best; i++)  {
                if(!bag.count(x + a[i])) y = x + a[i]; 
                x += a[i];
            }
            if(!bag.count(y)) {
                bag.insert(y);
                vis[id] = true;
            }
        }

        for(auto z : bag) cout << z << " ";
        cout << endl;
        int ans = 0;
        ans = (int)bag.size() * 2;
        cout << "Case #" << ++cont << ": " << ans << endl;
    }
    return 0;
}

