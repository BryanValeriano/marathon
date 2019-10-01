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


deque<int> lista;
map<int,bool> id;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    while(n--) {
        int x; cin >> x;
        if(id[x]) continue;
        lista.push_front(x);
        id[x] = 1;
        if(lista.size() > k) {
            x = lista.back();
            id[x] = 0;
            lista.pop_back();
        }
    }
    
    cout << lista.size() << endl;
    for(auto ok : lista) cout << ok << " ";
    cout << endl;
    
    
    return 0;
}

