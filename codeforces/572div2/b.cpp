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
 
const int T = 1e5 + 2;
int v[T];
int n;
deque<int> wtf;
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v+1, v+n+1);
 
    for(int i = n; i >= 1; i--) {
        if(i&1) wtf.pb(v[i]);
        else wtf.push_front(v[i]);
    }
 
    for(int i = 0; i < n; i++) {
        int l = i-1;
        int r = i+1;
        if(l < 0) l = n-1;
        if(r >= n) r = 0;
        if(wtf[i] >= wtf[l]+wtf[r]) { cout << "NO" << endl; return 0; }
    }
    
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << wtf[i] << " ";
    cout << endl;
 
    return 0;
}
 
