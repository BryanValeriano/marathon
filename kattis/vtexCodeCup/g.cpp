#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,int> ii;
typedef vector< pair<ll,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;

struct node {
    ll e,t,id;
};

vector<node> v;

char a[T];
ll b[T];
int n;
ll k;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    ll x, y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.pb({x,y,i});
    }

    sort(v.begin(), v.end(), [&] (const node &a, const node &b) {
        if(a.e < b.e) return 1;
        if(b.e < a.e) return 0;
        if(a.id < b.id) return 1;
        return 0;
    });

    ll A = 0, B = 0;
    ll tA = 0, tB = 0;
    ll last = v[0].e;

    priority_queue<ii, vii, greater<ii> > pq;


    for(int i = 0; i < n; i++) {
        ll z = v[i].e;
        tA = max(0LL, tA - (z-last));
        tB = max(0LL, tB - (z-last));

        while(!pq.empty()) {
            if(z >= pq.top().fi) {
                if(pq.top().se == 0) A--;
                else B--;
                pq.pop();
            } else break;
        }

        if(A <= B) {
            a[v[i].id] = 'A';
            tA += v[i].t;
            b[v[i].id] = tA + v[i].e;
            A++;
            pq.emplace(b[v[i].id], 0);
        } else {
            a[v[i].id] = 'B';
            tB += k*v[i].t;
            b[v[i].id] = tB + v[i].e;
            B++;
            pq.emplace(b[v[i].id], 1);
        }
        
        last = z;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " " << b[i] << endl;

    return 0;
}

