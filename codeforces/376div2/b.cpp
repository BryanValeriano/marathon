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
    int n; cin >> n;
    int carry = 0;;
    int at;
    for(int i = 0; i < n; i++) {
        cin >> at;
        at -= carry;
        if(at < 0) { cout << "NO" << endl; return 0; }
        if(at&1) carry = 1;
        else carry = 0;
    }
    if(carry) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}

