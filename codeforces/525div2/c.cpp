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
const int T = 2e3 + 10;
int v[T];
int aux[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int last = -1;
    vii track;
    for(int i = 1; i < n; i++) 
        if(v[i] > v[i-1]) { track.eb(last+1,i-1); last = i-1; }
   
    if(track.rbegin()->se != n-1) track.eb(track.rbegin()->se + 1, n-1);
    for(auto x : track) {
        cout << x.fi << " " << x.se << " ";
        int diff = abs(v[x.se] - v[x.fi]);
        cout << diff << endl;
    }
    return 0;
}

