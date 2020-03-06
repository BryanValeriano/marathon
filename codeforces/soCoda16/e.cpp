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

int n,x,y;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    if(x > y) {
        cout << n << endl;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v.pb(a);
    }

    int ok = v.size();
    sort(v.begin(), v.end());

    while(v.size()) {
        int i = 0;
        while(i < v.size()) {
            if(v[i] + (i+1)*y > x) break;
            i++;
        }
        if(v[i] - x > 0) break;

        v.erase(v.begin()+i);

        int id = -1;

        for(int i = 0; i < v.size(); i++)
            if(v[i] <= x and v[i]+y > x) { id = i; break; }

        if(id != -1) v[id] += y;

        sort(v.begin(),v.end());
    }

    cout << ok - v.size() << endl;

    return 0;
}

