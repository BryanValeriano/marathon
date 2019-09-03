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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 1e5 + 2;

vector<ll> cks;
ll sum[T];
ll maxi[T];
ll d;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d;
    fill(maxi,maxi+T,-INF);

    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
        if(sum[i] == 0) cks.pb(i);
        sum[i] += sum[i-1];
        if(sum[i] > d) { cout << -1 << endl; return 0; }
    }

    for(int i = n; i >= 1; i--) maxi[i] = max(sum[i],maxi[i+1]);


    int ans = 0;
    ll acum = 0;

    for(ll at : cks) {
        if(sum[at]+acum < 0) {
            ll can = d-acum-maxi[at];
            if(can < 0) { cout << -1 << endl; return 0; }
            acum += can;
            if(sum[at]+acum < 0) { cout << -1 << endl; return 0; }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

