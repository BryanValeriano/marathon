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

struct node {
    string a;
    int b, c;
    node(string a, int b, int c) :
        a(a), b(b), c(c) {}

    bool operator < (const node &v) {
        if(b != v.b) return b < v.b;
        else if(c != v.c) return c > v.c;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<node>ans;
        for(int i = 0; i < n; i++) {
            string a;
            int b, c;
            cin >> a >> b >> c;
            ans.pb(node(a,b,c));
        }
        sort(ans.begin(), ans.end());
        cout << ans.rbegin()->a  << endl;
    }
    return 0;
}

