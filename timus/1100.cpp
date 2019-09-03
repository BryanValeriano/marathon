#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
struct node {
    int id, pt, x;
};
 
vector<node> v;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int u,z;
 
    for(int i = 0; i < n; i++) {
        cin >> u >> z;
        v.pb({u,z,i});
    }
 
    sort(v.begin(), v.end(), [&] (const node &a, const node &b) {
        if(a.pt != b.pt) return a.pt < b.pt;
        return a.x > b.x;
    });
 
    for(int i = n-1; i >= 0; i--)
        cout << v[i].id << " " << v[i].pt << endl;
   
    return 0;
}
