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

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n; cin >> n;
    while(n--) {
        int a, b, k;
        cin >> a >> b >> k;
        a--; b--
        w = k % ((b-a)+1);
        string t = s;
        for(int i = a; i <= b; i++) {
            int next = ((i+k) % (b+1)) + (i+k >= b+1? a : 0);
            t[next] = s[i];
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}

