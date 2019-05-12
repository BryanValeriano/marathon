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

struct node {
    ll x,y,z;
};

vector<node> v;
int n;

ll mid(ll x, ll y, ll z) {
    if((y <= x and y >= z) or (y >= x and y <= z)) return y;
    if((x <= y and x >= z) or (x >= y and x <= z)) return x;
    if((z <= y and z >= x) or (z >= y and z <= x)) return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ll x,y,z;

    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        v.pb({max({x,y,z}),mid(x,y,z),min({x,y,z})});
    }

    sort(v.begin(), v.end(), [&] (const node &a, const node &b) {
        if(a.x > b.x) return 1;
        else if(b.x > a.x) return 0;
        if(a.y > b.y) return 1;
        else if(b.y > a.y) return 0;
        if(a.z > b.z) return 1;
        else if(b.z > a.z) return 0;
        return 1;
    });

    for(int i = 1; i < n; i++) {
        if(v[i].x >= v[i-1].x or v[i].y >= v[i-1].y or v[i].z >= v[i-1].z) {
            cout << "N" << endl;
            return 0;
        }  
    }

    cout << "S" << endl;
    return 0;
}

