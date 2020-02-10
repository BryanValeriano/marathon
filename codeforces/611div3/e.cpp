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

const int T = 2e5 + 5;
int sz[T];
int tmp[T];
int tmp2[T];
int v[T];
set<int> a;
set<int> b;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int j = -1; j < 2; j++) sz[v[i]+j]++;
    }

    sort(v, v+n);

    for(int i = 0; i < n; i++) {
        int small = INF;
        int pSmall = 0;
        int big = 0;
        int pBig = 0;

        for(int j = -1; j < 2; j++) {
            if(tmp2[v[i]+j] > big or (sz[v[i]+j] >  sz[pBig] and tmp2[v[i]+j] == big)) {
                big = tmp2[v[i]+j];
                pBig = v[i]+j;
            }
            if(tmp[v[i]+j] < small or (sz[v[i]+j] < sz[pSmall] and tmp[v[i]+j] == small)) {
                small = tmp[v[i]+j];
                pSmall = v[i]+j;
            }
        }

        a.insert(pBig);
        b.insert(pSmall);
        tmp[pSmall]++;
        tmp2[pBig]++;
        //cout << pBig << " " << pSmall << endl;
        for(int j = -1; j < 2; j++) sz[v[i]+j]--;
    }

    cout << a.size() << " " << b.size() << endl;


    return 0;
}

