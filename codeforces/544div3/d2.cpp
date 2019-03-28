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

const int T = 2e5 + 10;
double a[T];
double b[T];
int n;

map<double,ll> ansA;
map<double,ll> ansB;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int ga = 0;
    int gb = 0;
    ll x;
    for(int i = 0; i < n; i++) cin >> x, a[i] = x;
    for(int i = 0; i < n; i++) cin >> x, b[i] = x;

    for(int i = 0; i < n; i++) { 
        if(a[i] and b[i]) ansA[b[i]/a[i]]++;
        else if(!a[i] and !b[i]) ga++;
    } 
    for(int i = 0; i < n; i++) {
        if(b[i] and a[i]) ansB[a[i]/b[i]]++;
        else if(!a[i] and !b[i]) gb++;
    }

    ll best = max(ga,gb);

    for(auto x : ansA) 
        best = max(best, x.se + ga);
    for(auto x : ansB) 
        best = max(best, x.se + gb);

    cout << best << endl;

    return 0;
}

