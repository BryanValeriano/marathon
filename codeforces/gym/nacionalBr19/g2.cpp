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
vector<int> c(T), p(T), cn(T), pn(T), cnt(T), dp(T);
string s;
int q;

void sortShifts() {
    int n = s.size();
    int tam = 256;
    fill(cnt.begin(), cnt.begin() + n, 0);

    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < tam; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    int cls = 1;
    c[p[0]] = 0;

    for(int i = 1; i < n; i++) {
        if(s[p[i]] != s[p[i-1]]) cls++;
        c[p[i]] = cls-1;
    }

    int h = 1;

    while(cls != n) {

        for(int i = 0; i < n; i++) {
            pn[i] = p[i] - h;
            if(pn[i] < 0) pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + n, 0);

        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < cls; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        cls = 1;

        for(int i = 1; i < n; i++) {
            ii prev = {c[p[i-1]], p[i-1] + h < n? c[p[i-1] + h] : -1};
            ii at = {c[p[i]], p[i] + h < n? c[p[i] + h] : -1};
            if(at != prev) ++cls;
            cn[p[i]] = cls-1;
        }

        c.swap(cn);
        h <<= 1;
    }
}

void construct() {
    s += "$";
    sortShifts();
    p.erase(p.begin());
    s.pop_back();
}

bool bigger(int pos, string &x, int k1) {
    //cout << "query: " << pos << endl;
    for(int i = k1; i < x.size(); i++) {
        int j = i-k1;
        //cout << s[p[pos]+j] << " " << x[i] << endl;
        if(j+p[pos] >= p.size() or s[p[pos]+j] < x[i]) return false;
        if(s[p[pos]+j] > x[i]) return true;
    }
    return false;
}

int query(string x, int k1) {
    int l = 0;
    int r = s.size()-1;
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(bigger(mid,x,k1,k2)) r = mid-1;
        else ans = mid, l = mid+1;
    }

    //cout << k1 << " " << k2 << " resultado da query " << ans << endl;

    for(int i = k1; i < x.size(); i++) {
        int j = i-k1;
        if(j+p[ans] >= p.size() or x[i] != s[p[ans]+j]) return false;
    }


    return true;
}


int minQuery(int a, int b, vector<ii> &stk) {
    if(b < a) return INF;
    int l = 0;
    int r = stk.size()-1;
    int ans = r;

    while(l <= r) {
        int mid = (l+r)>>1;
        if(stk[mid].se > b) l = mid+1;
        else ans = mid, r = mid-1;
    }

    return stk[ans].fi;
}

int solve(string &x) {
    int n = x.size();
    vector<ii> stk;
    dp[n] = 0;
    stk.eb(0,n);

    //cout << x << endl;
    for(int i = n-1; i >= 0; i--) {
        int great = query(x,i);
        dp[i] = 1 + minQuery(i+1,i+great,stk);
        //cout << "minQuery: " << minQuery(i+1,i+great,stk) << endl;
        while(dp[i] < stk.back().fi) stk.pop_back();
        stk.eb(dp[i],i);
        //cout << i << " " << great << " " << dp[i] << endl;
    }

    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    cin >> q;
    construct();
    while(q--) {
        string x;
        cin >> x;
        int tmp = solve(x);
        cout << (tmp >= INF? -1 : tmp) << endl;
    }
    return 0;
}

