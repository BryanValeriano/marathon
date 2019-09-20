#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+3;
int v[T];
int l[T];
int r[T];
int n;

void partiu() {
    cout << "NO" << endl;
    exit(0);
}

vector<int> pegaMax() {
    vector<int> ok;
    for(int i = 0; i < n; i++) {
        if(r[i] == l[i] and r[i] == 0 and !v[i]) ok.pb(i);
        if(r[i] < 0 or l[i] < 0) partiu();
    }
    return ok;
}

void updateL(int pos) {
    for(int i = pos+1; i < n; i++) {
        if(!v[i]) l[i]--;
        if(l[i] < 0) partiu();
    }
}

void updateR(int pos) {
    for(int i = pos - 1; i >= 0; i--) {
        if(!v[i]) r[i]--;
        if(r[i] < 0) partiu();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];


    int vis = 0;
    int maxi = n;

    while(vis < n) {
        vector<int> ok = pegaMax();
        if(ok.size() == 0) partiu();
        for(int i = 0; i < ok.size(); i++) v[ok[i]] = maxi;
        for(int i = 0; i < ok.size(); i++) {
            updateL(ok[i]);
            updateR(ok[i]);
        }
        vis += ok.size();
        maxi--;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}

