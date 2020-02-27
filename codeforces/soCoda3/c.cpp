#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string s;

bool check(int l, int r) {
    if(r >= s.size()) return 0;

    for(int i = l+1; i < r; i++) {
        for(int k = 1; i+k <= r and i-k >= l; k++) {
            if(s[i-k] == s[i] and s[i] == s[i+k]) return 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;

    int l = 0;
    int r = 0;
    ll ans = 0;
    ll n = s.size();

    while(r < n) {
        while(!check(l,r) and r < n) r++;
        ans += (n-r);
        l++;
    }

    cout << ans << endl;


    return 0;
}

