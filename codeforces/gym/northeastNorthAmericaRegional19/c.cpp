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
const int T = 1e7+5;
ll rest[T], sum[T], need[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> k >> n;
    ll tot = 0;

    for(int i = 0; i < n; i++) {
        cin >> sum[i];
        tot += sum[i];
    }

    if(tot%k) {
        cout << "NO" << endl;
        return 0;
    }

    tot /= k;
    for(int i = tot; i < 2*tot; i++) need[i%tot] = i;

    ll aux = (sum[0]%tot);
    if(need[aux] == sum[0]) {
        rest[aux]++;
        need[aux] += tot;
    }

    for(int i = 1; i < n; i++) {
        sum[i] += sum[i-1];
        aux = (sum[i]%tot);

        if(need[aux] == sum[i]) {
            rest[aux]++;
            need[aux] += tot;
        }

        if(rest[aux]==(k-1)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    memset(rest, 0, sizeof rest);
    for(int i = 1; i <= tot; i++) need[i%tot] = i;

    aux = (sum[0]%tot);
    if(need[aux] == sum[0]) {
        rest[aux]++;
        need[aux] += tot;
    }

    for(int i = 1; i < n; i++) {
        aux = (sum[i]%tot);

        if(need[aux] == sum[i]) {
            rest[aux]++;
            need[aux] += tot;
        }

        if(rest[aux]==(k-1)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}

