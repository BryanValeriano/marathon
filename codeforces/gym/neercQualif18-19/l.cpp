#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

set<int> impA1, impA2, parA1, parA2;
set<int> impB1, impB2, parB1, parB2;

vector<int> v1;
vector<int> v2;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,x; 
    int ans = 0;

    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> x, v1.pb(x);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> x, v2.pb(x); 
        if(binary_search(v1.begin(),v1.end(),x)) ans = 2;
    }

    int passo = 2;

    for(int i = 0; i <= 40; i++) {
        int ok = passo >> 1;
        unordered_map<int,int> fuk1;
        unordered_map<int,int> fuk2;

        for(int i = 0; i < v1.size(); i++) { 
            x = v1[i];

            fuk1[(x+ok)%passo]++;
            fuk2[x%passo]++;
            ans = max({ans, fuk1[(x+ok)%passo], fuk2[x%passo]});
        }

        for(int i = 0; i < v2.size(); i++) { 
            x = v2[i];
        
            fuk2[(x+ok)%passo]++;
            fuk1[x%passo]++;
            ans = max({ans, fuk1[x%passo], fuk2[(x+ok)%passo]});
        }
        
        passo <<= 1;
    }

    cout << ans << endl; 
    return 0;
}

