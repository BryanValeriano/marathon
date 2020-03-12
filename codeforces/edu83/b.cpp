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

const int T = 102;
int v[T];
int n;

bool ok() {
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(i+1-v[i] == j+1-v[j]) return 0;

    return 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;

        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v, v+n);
        if(!ok()) sort(v,v+n,greater<int>());
        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;

    }
    return 0;
}

