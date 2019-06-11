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
    stack<int> pilha;
    int n; cin >> n;

    ll ans = 0, at = 1;
    ll up = 0;
    ll lim = (1LL << 32) - 1;
    string s;
    int x;
    

    while(n--) {
        cin >> s;
        if(s == "for") {
            cin >> x;
            pilha.push(x);
            if(up or lim/x < at) up++;
            else at *= x;
        } else if(s == "end") {
            ll tmp = pilha.top();
            pilha.pop();
            if(!up) at /= tmp;
            else up--;
        } else {
            if(up or ans + at > lim) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            } else {
                ans += at;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

