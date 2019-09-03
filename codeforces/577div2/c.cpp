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

int n,k;
vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    int mid = n/2;

    ll passo = 1;


    while(mid < n-1) {
        ll dist = v[mid+1] - v[mid];
        if(dist*passo <= k) k -= dist*passo, mid++, passo++;
        else break;
    }


    ll acum = 0;
    if(k) acum = k/passo;

    cout << v[mid] + acum << endl;

    return 0;
}

