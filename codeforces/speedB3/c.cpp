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

const int T = 2e5 + 3;
ll v[T];
ll n,s;
ll maxi;
ll mini;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    mini = n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        maxi += v[i];
    }


    for(int i = 0; i < n; i++) {
        ll low = max(0LL, s - (maxi-v[i]));
        ll high = max(0LL, s - (mini-1));
        low = max(0LL,low-1);
        high = max(0LL, v[i]-high);
        cout << low+high << " ";
    }

    cout << endl;
    return 0;
}

