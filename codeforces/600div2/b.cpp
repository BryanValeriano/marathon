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
const int T = 1e6 + 3;
int v[T];
int freq[T];

void fuc() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int dentro = 0;
    vector<int> ok;
    vector<int> log;
    int mov = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mov++;
        if(x > 0) {
            if(v[x] or freq[x]) fuc();
            v[x]++;
            freq[x]++;
            dentro++;
            log.pb(x);
        } else {
            x = -x;
            if(v[x] == 0) fuc();
            v[x]--;
            dentro--;
        }
        if(dentro == 0) {
            ok.pb(mov), mov = 0;
            for(int z : log) freq[z] = 0;
            log.clear();
        }
    }

    if(dentro) fuc();
    cout << ok.size() << endl;
    for(int x : ok) cout << x << " ";
    cout << endl;

    return 0;
}

