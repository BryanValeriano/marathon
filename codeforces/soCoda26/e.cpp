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
const int T = 2e5 + 10;
vector<int> p(T), c(T), cnt(T);
vector<int> pn(T), cn(T), lcp(T);
string s;

void sufArray() {
    int n = s.size();
    const int alp = 256;
    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < alp; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;

    for(int i = 1; i < n; i++) {
        if(s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes-1;
    }

    for(int h = 0; (1 << h) < n; ++h) {
        for(int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) pn[i] += n;
        }

        fill(cnt.begin(),cnt.begin()+classes,0);
        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;

        for(int i = 1; i < n; i++) {
            ii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            ii prev = {c[p[i-1]], c[(p[i-1] + (1 << h))%n]};
            if(cur != prev) ++classes;
            cn[p[i]] = classes-1;
        }

        swap(c,cn);
    }
}

void lcpBuild() {
    int n = s.size();
    vector<int> rank(n,0);
    for(int i = 0; i < n; i++) rank[p[i]] = i;
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(rank[i] == n-1) { k = 0; continue; }
        int j = p[rank[i]+1];
        while(i + k < n and j + k < n and s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    string s1,s2;
    cin >> s1 >> s2;
    s = s1 + "$" + s2 + "$";

    sufArray();
    p.erase(p.begin());
    lcpBuild();
    int ans = 0;
    int ok = 0;

    for(int i = 0; i < s.size(); i++) {
        if(lcp[i] > ans) {
            ans = lcp[i];
            ok = i;
        }
    }

    cout << ans << endl;

    return 0;
}

