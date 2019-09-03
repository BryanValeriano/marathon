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
    int casa = 0;
    ll ans = 0;

    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == '1') ans += 2*casa;
        casa++;
    }
    ll r = 1;
    ll q = 0;

    while(r*4 <= ans) q++, r++;
    cout << q << endl;
    return 0;
}

