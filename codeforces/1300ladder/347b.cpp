#include <bits/stdc++.h>
using namespace std;
//
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(v[i] < n and v[i] != i and v[v[i]] == i) { 
            swap(v[v[i]], v[i]);
            flag = true;
            break;
        }
    }
    if(!flag) {
        for(int i = 0; i < n; i++) {
            if(v[i] < n and v[v[i]] != v[i]) {
                swap(v[v[i]], v[i]);
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) 
        if(v[i] == i) ans++;
    cout << ans << endl;

    return 0;
}

