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

string s;

int calc(int pos, string x) {
    int ini = pos - 3;
    int ans = 0;
    for(int i = ini; i <= pos; i++) {
        int AX = s[i] - 'A' + 'Z' - x[i-ini] + 1;
        int XA = 'Z' - s[i] + x[i-ini] - 'A' + 1;
        ans += min({abs(x[i-ini] - s[i]), AX, XA}); 
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin >> s;
    string x = "ACTG";

    int dist = INF;

    for(int i = 3; i < n; i++) 
        dist = min(dist, calc(i,x));

    cout << dist << endl;

    return 0;
}

