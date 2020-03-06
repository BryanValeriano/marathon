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
ll v[T];
ll freq[T];
int n;

void print(int x) {
    if(x == 0) {
        cout << n << endl;
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
    }
    else if(x < 0) {
        cout << 1 << endl << -x << endl;
    } else if(x <= n) {
        cout << 2 << endl;
        cout << x << " ";
        for(int i = 1; i <= n; i++) {
            if(v[i] == -v[x]) {
                cout << i << endl;
                break;
            }
        }
    } else {
        x -= n+n;
        cout << x << endl;
        for(int i = 1; i <= x; i++) cout << i << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        ll sum = 0;

        for(int i = 0; i <= n; i++) freq[i] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
            freq[abs(v[i])] |= (v[i] < 0? 1 : 2);
        }

        if(sum == 0) { print(0); continue; }
        int i;
        sum = 0;

        for(i = 1; i <= n; i++) {
            sum += v[i];
            if(v[i] == 0) { print(-i); break; }
            if(freq[abs(v[i])] == 3) { print(i); break; }
            if(sum == 0) { print(i+n+n); break; }
        }
        //if(i > n) cout << " AAAAAAAAAAAA " << endl;
    }

    return 0;
}

