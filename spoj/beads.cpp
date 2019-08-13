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

const int T = 1e5 + 3;
vector<int> c(T), p(T), cn(T), pn(T), cnt(T);
string s;

void shift() {
    int n = s.size();
    int alphabet = 256;

    fill(cnt.begin(), cnt.begin() + max(alphabet,n), 0);

    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    
    c[p[0]] = 0;
    int cls = 1;

    for(int i = 1; i < n; i++) {
        if(s[p[i]] != s[p[i-1]]) cls++;
        c[p[i]] = cls-1;
    }

    int h = 0;

    while(h < n) {
        for(int i = 0; i < n; i++) {
            pn[i] = p[i] - h;
            if(pn[i] < 0) pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + cls, 0);

        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < cls; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        cls = 1;

        for(int i = 1; i < n; i++) {
            ii prev = {c[p[i-1]], c[(p[i-1]+h) % n]};
            ii at = {c[p[i]], c[(p[i]+h) % n]};
            if(at != prev) ++cls;
            cn[p[i]] = cls-1;
        }
        c.swap(cn); 
        h <<= 1; 
        if(h == 0) ++h;
    }
}

bool allEq() {
    for(int i = 1; i < s.size(); i++) if(s[i] != s[i-1]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    //int tc; cin >> tc;
    //while(tc--) {
        cin >> s;
        if(allEq()) { cout << 0 << endl; return 0; }
        shift();
        cout << p[0] << endl;
    //}

    return 0;
}

