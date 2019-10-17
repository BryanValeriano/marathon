#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define mt  make_tuple
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e3 + 5;

int n;
int a[T];
int b[T];
int c[T];
bool vis[T];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x,y,z;
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        int ch = 0;

        for(int j = i+1; j <= n; j++) {
            if(vis[j] or i == j) continue;
            if(!ch) ch = j;

            if(min(a[i],a[ch]) <= a[j] and max(a[i],a[ch]) >= a[j] and
                min(b[i],b[ch]) <= b[j] and max(b[i],b[ch]) >= b[j] and
                min(c[i],c[ch]) <= c[j] and max(c[i],c[ch]) >= c[j])
                    ch = j;
        }

        cout << i << " " << ch << endl;
        vis[i] = vis[ch] = 1;
    }

    return 0;
}

