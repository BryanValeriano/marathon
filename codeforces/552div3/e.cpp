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

const int T = 2e5 + 10;

vector<ii> v;
set<int> pos;
int ans[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n, k, x;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        pos.insert(i);
        cin >> x;
        v.eb(x,i);
    }

    sort(v.begin(), v.end()); 

    int turno = 0;
    x = n-1;
    
    while(x >= 0) {
        ii at = v[x];
        x--;
        
        if(!pos.size()) continue;
        if(ans[at.se]) continue;

        ans[at.se] = turno + 1;
        vector<int> tira;

        auto iter = pos.find(at.se);
        tira.pb(*iter);

        for(int oper = 0; oper < k; oper++) {
            if(iter == pos.begin()) break;
            --iter;
            ans[*iter] = turno + 1;
            tira.pb(*iter);
        }
   
        iter = pos.find(at.se);

        for(int oper = 0; oper < k; oper++) {
            ++iter;
            if(iter == pos.end()) break;
            ans[*iter] = turno + 1;
            tira.pb(*iter);
        }

        for(auto x : tira) pos.erase(x);
        turno = 1 - turno;
    }

    for(int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
    
    return 0;
}

