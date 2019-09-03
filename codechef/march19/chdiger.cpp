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

string solve(string n, char d, int ini) {
    char mini = d;
    int pos = n.size();
    for(int i = ini; i < n.size(); i++) {
        if(n[i] < mini) {
            mini = n[i];
            pos = i;
        }
    }
    string x;
    x += mini;
    if(mini != d) return (x + solve(n,d,pos+1));
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string n; char d;
    while(tc--) {
        cin >> n >> d;
        string ans = solve(n,d,0);
        while(ans.size() < n.size()) ans += d;
        cout << ans << endl;
    }
    return 0;
}

