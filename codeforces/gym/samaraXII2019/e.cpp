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

struct node {
    int x, y, id;

    bool operator < (const node &b)  const {
        if(y != b.y) return y < b.y;
        if(x != b.x) return x > b.x;
        return id > b.id;
    }
};

priority_queue<node, vector<node> > pq;

vector<node> v;
vector<int> ans;
int n,m;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int a,b;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a,b,i+1});
    }

    sort(v.begin(), v.end(), [&] (const node &a, const node &b){
        if(a.x != b.x) return a.x < b.x;
        if(a.y != b.y) return a.y > b.y;
        return a.id < b.id;
    });


    if(v[0].x > 1) {
        cout << "NO" << endl;
        return 0;
    }

    int r = v[0].y;
    ans.pb(v[0].id);

    for(int i = 1; i < n; i++) {
        if(v[i].x > r+1) {
            if(pq.empty()) {
                cout << "NO" << endl;
                return 0;
            } else {
                node at = pq.top();
                ans.pb(at.id);
                pq.pop();
                r = max(r,at.y);
                if(r+1 < v[i].x) {
                    cout << "NO" << endl;
                    return 0;
                }
                pq.push({v[i]});
            }
        } else pq.push({v[i]});
    }


    if(r < m) {
        if(pq.empty()) {
            cout << "NO" << endl;
            return 0;
        } else {
            node at = pq.top();
            ans.pb(at.id);
            pq.pop();
            r = at.y;
        }
    }

    if(r < m) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto w : ans) cout << w << " ";
    cout << endl;

    return 0;
}

