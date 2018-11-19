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
const int T = 1e5 + 3;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        set<int> id[T];
        int row[T];
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> row[i];
        for(int i = 1; i <= n; i++)
            id[row[row[i]]].insert(row[i]);
        bool flag = false;
        for(int i = 1; i <= n; i++)
            if(id[i].size() >= 2) { flag = true; break; }
        cout << (flag? "Truly Happy" : "Poor Chef") << endl;
    }

    return 0;
}

