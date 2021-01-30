#include <bits/stdc++.h>
using namespace std;

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
const int T= 2e5+3;
ll v[T], freq[T], r[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    ll ans = 0;

    for(int i = 1; i < T; i++) {
        r[i] = max(0ll, freq[i]*(freq[i]-1)>>1);
        ans += r[i];
    }

    for(int i = 0; i < n; i++) {
        ans -= r[v[i]];
        freq[v[i]]--;
        ans += max(0ll, freq[v[i]]*(freq[v[i]]-1)>>1);
        cout << ans << endl;
        ans -= max(0ll, freq[v[i]]*(freq[v[i]]-1)>>1);
        ans += r[v[i]];
        freq[v[i]]++;
    }


    return 0;
}

