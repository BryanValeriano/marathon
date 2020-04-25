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
const int T = 5e5;
ll freq[T];
map<int,ll> offset;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int,int> id;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        offset[a[i]-b[i]]++;
        id[a[i]-b[i]]++;
        id[-1*(a[i]-b[i])]++;
    }

    int ok = 1;
    for(auto x : id) id[x.fi] = ++ok;

    ll last = 0;
    for(auto x : offset) freq[id[x.fi]] = x.se;
    for(int i = ok; i >= 0; i--) freq[i] += freq[i+1];

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int off = id[-1*(a[i]-b[i])];
        ans += freq[off+1];
        if(id[a[i]-b[i]] > off) ans--;
    }
    cout << (ans>>1) << endl;


    return 0;
}

