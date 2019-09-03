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
int ans[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    ans[0] = 1;
    cin >> v[0];
    for(int i = 1; i < n; i++) {
        cin >> v[i];
        if(v[i] > v[i-1]) ans[i] = 1; 
        if(v[i] < v[i-1]) ans[i] = -1;
    }
    for(int i = 0; i < n-1; i++) {
        if(v[i] == v[i+1])
        for(int i = 1; i < n; i++) ans[i] += ans[i-1];
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;


    return 0;
}

