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
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    int r = n-1;
    int last = -1;
    string ans = "";

    while(l <= r) {
        if(v[l] > last and v[r] > last) {
            if(v[l] < v[r]) ans += 'L', last = v[l], l++;
            else ans += 'R', last = v[r], r--;
        } 
        else if(v[l] > last) ans += 'L', last = v[l], l++;
        else if(v[r] > last) ans += 'R', last = v[r], r--;
        else break;
    }
    
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}

