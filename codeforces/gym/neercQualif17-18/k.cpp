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

const int T = 305;

unordered_map<string,int> ind;
int from[T];
int to[T];
map< ii, int > tot;

int main() {
    ios::sync_with_stdio(false);
    int n,a,b,k,f;
    cin >> n >> a >> b >> k >> f;
    string s,t;
    int cont = 0;

    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        if(!ind.count(s)) ind[s] = cont++;
        if(!ind.count(t)) ind[t] = cont++;
        from[i] = ind[s];
        to[i] = ind[t];
    }

    for(int i = 0; i < n; i++) {
        int c = 0;
        if(i == 0 or to[i-1] != from[i]) c = a;
        else c = b;
        tot[ii(min(from[i],to[i]), max(from[i],to[i]))] += c;
    }

    vector<int> p;
    for(auto z : tot) p.pb(z.se);
    sort(p.begin(), p.end(), greater<int>());

    int ans = 0;

    for(int i = 0; i < p.size(); i++) {
        if(i < k) ans += min(f, p[i]);
        else ans += p[i];
    }

    cout << ans << endl;


    return 0;
}

