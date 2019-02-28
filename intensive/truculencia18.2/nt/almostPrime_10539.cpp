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
const int T = 1e6 + 1;
bitset<T> crivo;
vector<ll> primes;
vector<ll> almost;

void gen() {
    for(int i = 2; i < T; i++) {
        if(crivo[i] == false) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

void pop() {
    for(int i = 0; i < primes.size(); i++) {
        for(int j = 2; ; j++) {
            ll x = pow(primes[i],j);
            if(x <= 1e12) almost.pb(x);
            else break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    gen();
    pop();
    sort(almost.begin(), almost.end());
    int tc; cin >> tc;
    while(tc--) {
        ll low, high;
        cin >> low >> high;
        int h = upper_bound(almost.begin(), almost.end(), high) - almost.begin();
        int l = lower_bound(almost.begin(), almost.end(), low) - almost.begin();
        //cout << l << " " << h << " ";
        cout << h-l << endl;
    }
    return 0;
}

