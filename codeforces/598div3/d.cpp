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
const int T = 1e6 + 5;

ll n,k;
ll v[T];
ll zeros = 0;
ll ums = 0;
ll at = 0;

void print(int x) {
    for(int i = 0; i < zeros; i++) cout << 0;
    for(int i = 0; i < ums-x; i++) cout << 1;
    cout << 0;
    for(int i = ums-x; i < ums; i++) cout << 1;
    for(int i = at+1; i < n; i++) cout << v[i];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        string s; cin >> s;
        for(int i = 0; i < n; i++) v[i] = s[i] - '0';

        zeros = ums = at = 0;

        while(at < n) {
            if(v[at] == 1) ums++;
            else {
                if(k >= ums) zeros++, k -= ums;
                else { print(k); break; }
            }
            at++;
        }
        if(at == n) {
            sort(v,v+n);
            for(int i = 0; i < n; i++) cout << v[i];
            cout << endl;
        }
    }

    return 0;
}

