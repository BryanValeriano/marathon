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

class comp {
    public:
    bool operator() (const ii &a, const ii &b) {
        return a.se < b.se;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    map<int,int> track;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        track[aux]++;
    }
    map<int,int>vez;
    priority_queue<ii, vii, comp > pq;
    for(auto x : track) pq.push(x);
    vector<int>ans;
    for(int i = 0; i < k; i++) {
        ii x = pq.top();
        pq.pop();
        ans.pb(x.fi);
        int aux = 0;
        int h = 2;
        if(vez.count(x.fi)) h = vez[x.fi];
        else vez[x.fi] = 2; 
        x.se = track[x.fi]/h;
        vez[x.fi]++;
        pq.push(x);
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

