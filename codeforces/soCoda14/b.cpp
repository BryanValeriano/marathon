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

map<ll,ll> freq;
vector<ll> v;
ll a;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a;
    cin >> s;
    ll ans2 = 0;

    for(int i = 0; i < s.size(); i++) v.pb(s[i] - '0');

    for(int i = 0; i < v.size(); i++) {
        ll sum = 0;
        for(int j = i; j < v.size(); j++) {
            sum += v[j];
            freq[sum]++;
        }
    }

    ll ans = 0;
    ll n = v.size();
    ll full = (n*(n+1)) >> 1;

    for(int i = 0; i < v.size(); i++) {
        ll sum = 0;
        for(int j = i; j < v.size(); j++) {
            sum += v[j];

            if(a == 0) {
                if(sum != 0) ans += freq[0];
                else ans += full;
                continue;
            }

            if(sum == 0 or a%sum) continue;
            ans += freq[a/sum];
        }
    }

    cout << ans << endl;



    return 0;
}

