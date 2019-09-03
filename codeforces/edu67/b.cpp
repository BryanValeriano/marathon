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

const int T = 2e5 + 5;
int v[T][30];
int p[30];
int n;
string s;
string t;

bool check(int x) {
    bool ok = 1;

    for(int i = 0; i < 30; i++)
        ok &= (p[i] <= v[x][i]);

    return ok;
}

int binSearch() {

    int l = 0;
    int r = n;
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;

    for(int i = 0; i < n; i++) v[i][s[i]-'a']++;

    for(int j = 0; j <= 'z' - 'a'; j++)
        for(int i = 1; i < n; i++) 
            v[i][j] += v[i-1][j];
    
    int q; cin >> q;

    while(q--) {
        cin >> t;
        memset(p, 0, sizeof p);
        for(int i = 0; i < t.size(); i++) p[t[i]-'a']++;
        cout << binSearch()+1 << endl;
    }
        
    return 0;
}

