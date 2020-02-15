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
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> cnt;
    ll ans = 0;
    for (int i = 0;i < n;i++) {
        string x;
        cin >> x;
        char next = 'A';
        map<char, char> conv;
        for (char& c : x) {
            if (!conv[c]) {
                conv[c] = next++;
            }
            c = conv[c];
        }
        cnt[x]++;
    }
    for (auto& p : cnt) {
        ll q = p.second;
        ans += (q * (q - 1)) / 2;
    }
    cout << ans << endl;
    
    return 0;
}

