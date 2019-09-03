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

string a[3];
int maxEqual[3][3];
vector<int> v[3];
// 0   1    2    3    4    5
//abc acb, bac, bca, cab, cba;

vector<int> shift(int x) {
    string s = a[x];
    int n = s.size();
    int alphabet = 256;

    vector<int> c(n), p(n), cn(n), pn(n), cnt(max(n,alphabet),0);

    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < n; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    int cls = 1;
    c[p[0]] = 0;

    for(int i = 1; i < n; i++) {
        cls += (s[i] != s[i-1]);
        c[p[i]] = cls-1;
    }

    int h = 1;

    while(h < n) {
        for(int i = 0; i < n; i++) {
            pn[i] = p[i] - h;
            if(pn[i] < 0) pn[i] += n;
        }

        fill(cnt.begin(), cnt.begin() + cls, 0);

        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < cls; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cls = 1;
        cn[p[0]] = 0;

        for(int i = 1; i < n; i++) {
            ii prev = {c[p[i-1]], p[i-1] + h < n? c[p[i-1] + h] : -1};
            ii at = {c[p[i]], p[i] + h < n? c[p[i] + h] : -1};
            cls += (at != prev);
            cn[p[i]] = cls - 1;
        }

        c.swap(cn);
        h <<= 1;
    }

    return p;
}


vector<int> build(int x) {
    a[x] += "$";
    vector<int> p = shift(x);
    p.erase(p.begin());
    a[x].pop_back();
    return p;
}

bool bigger(int suf, int mid, int pref, int pos) {
    int t = 0;

    for(int i = v[suf][mid]; i < (int)a[suf].size(); i++) {
        if(t > pos) return true;
        if(a[suf][i] < a[pref][t++]) return false;
        if(a[suf][i] > a[pref][t++]) return true;
    }

    return true;
}


bool search(int suf, int pref, int pos) {
    int l = 0;
    int r = a[suf].size()-1;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(bigger(suf,mid,pref,pos)) r = mid-1;
        else l = mid+1;
    }

    int t = 0;
    cout << "receio q n " << suf << " " << pref << " " << v[suf][l] << endl;

    for(int i = v[suf][l]; i < (int)a[suf].size(); i++) {
        if(t > pos) return true;
        if(a[suf][i] != a[pref][t++]) return false;
    }

    return true;
}

int bind(int x, int y) {
    int ans = 0;

    for(int i = 0; i < (int)a[y].size(); i++) 
        if(search(x,y,i)) ans = i+1;
   
   return ans;
}    

void buildMaxEqual() {
    for(int i = 0; i < 3; i++) 
        for(int j = 1; j < 3; j++) {
            maxEqual[i][(i+j)%3] = bind(i, (i+j)%3);
            cout << i << " " << (i+j)%3 << " | " << maxEqual[i][(i+j)%3] << endl;
        }
}

int best() {
    vector<int> perm = {0,1,2};
    int ans = 0;

    do { 
        ans = max(ans, maxEqual[perm[0]][perm[1]] + maxEqual[perm[1]][perm[2]]);
    } while(next_permutation(perm.begin(), perm.end()));
    
    return (a[0].size() + a[1].size() + a[2].size() - ans);
}

int main() {
    ios::sync_with_stdio(false);

    while(cin >> a[0]) {
        cin >> a[1] >> a[2];
        v[0] = build(0);
        v[1] = build(1);
        v[2] = build(2);
        buildMaxEqual();
        cout << best() << endl;
    }

    return 0;
}

