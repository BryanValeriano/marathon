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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e7;

unordered_set<ll> bag;
ll p, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> p >> n;

    ll passo = 1;
    ll at = 0;

    while(bag.size() < p and passo <= n) {
        bag.insert(at);
        at += passo;
        passo++;
        at %= p;
        cout << bag.size() << " " << at << endl;
    }

    cout << bag.size() << endl;

    return 0;
}

