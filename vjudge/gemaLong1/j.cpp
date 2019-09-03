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

vii hist;
bool at[T];
int close[T];
set<int> bag;
int ans;
int n;

int main() {
    ios::sync_with_stdio(false);
    int a,b;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        hist.eb(a,i);
        hist.eb(b,i);
        close[i] = b;
    }

    sort(hist.begin(), hist.end());

    for(int i = 0; i < 2*n; i++) {
        a = hist[i].se;
        if(!at[a]) {
            if(bag.size() and *bag.rbegin() > close[a]) ans++;
            bag.insert(close[a]);
            at[a] = 1;
        }
        else bag.erase(close[a]); 
    }

    cout << ans << endl;

    return 0;
}

