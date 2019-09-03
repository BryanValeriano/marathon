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

const int T = 1e5 + 10;
const int LOG = 21;
int bit[T];

void update(int pos, int val) {
    for(; pos < T; pos += pos&-pos) bit[pos] += val;
}

int query(int pos) {
    int ans = 0;
    for(; pos > 0; pos -= pos&-pos) ans += bit[pos];
    return ans;
}

int binLift(int v) {
    int sum = 0;
    int pos = 0;

    for(int i = LOG; i >= 0; i--) {
        if(pos + (1<<i) < T and sum + bit[pos + (1<<i)] < v) {
            sum += bit[pos + (1<<i)];
            pos += (1<<i);
        }
    }
    return pos+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    int x;
    int at = 1;
    int tot = n;
    for(int i = 1; i <= n; i++) update(i,1);

    while(tot) {
        at = (at+k-1) % tot;
        if(at == 0) at = tot;
        x = binLift(at);
        cout << x << " ";
        update(x,-1);
        tot--;
    }

    cout << endl;

    return 0;
}

