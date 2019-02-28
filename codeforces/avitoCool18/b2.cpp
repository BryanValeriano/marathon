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
    int n; cin >> n;
    int aux;
    map<int,int> ans;
    vector<int> row;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        ans[aux]++;
        row.pb(aux);
    }
    if(ans.size() == 1 and ans.rbegin()->fi == 0) {
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++) cout << 1 << " ";
        cout << endl;
    }
    else if(ans.size() == 2 and ans.rbegin()->fi == ans.begin()->se
            and ans.rbegin()->se == ans.begin()->fi) {
        cout << "Possible" << endl;
        for(int x : row) cout << x << " ";
        cout << endl;
    }
    else if(ans.size() == 1 and  (((double)sqrt(n)  == (ans.begin()->fi)) or (ans.begin()->fi == n-1) or (n%2 == 0 and 
                n/2 == ans.begin()->fi))) { 
        cout << "Possible" << endl;
        if(ans.begin()->fi == n-1) for(int i = 1; i <= n; i++) cout << i%n + 1 << " ";
        else for(int i = 1; i <= n; i++) cout << i%(ans.begin()->fi) + 1 << " ";
        cout << endl;
    }
    else if(ans.size() == 2 and n % 1 == 0 and (((ans.rbegin()->fi == n-1 and ans.begin()->se == n-1)
                    and ans.begin()->fi == (n/2)+1) or ((ans.begin()->fi == n-1 and ans.rbegin()->se == n-1) and
                    ans.rbegin()->fi == (n/2)+1))) {
        cout << "Possible" << endl;
        int um = 0;
        int dois = 0;
        for(int i = 0; i < n; i++) {
            if(row[i] == n-1) cout << row[i] << " ";
            else if(um++ < n/2) cout << 1 << " "; 
            else cout << 2 << " ";
        }
        cout << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}

