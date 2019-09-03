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
int v[T];
set<int>ans;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            int k;
            cin >> k;
            v[k]++;
        }
    }
    for(int i = 0; i < T; i++) 
        if(v[i] == n) 
            ans.insert(i);

    for(auto v : ans) cout << v << " ";
    cout << endl;

    return 0;
}

