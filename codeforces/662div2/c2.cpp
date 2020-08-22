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
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
int v[T], last[T], vv[T];
int n;

bool check(int k) {
    if(!k) return true;
    for(int i = 0; i < n; i++) last[i] = -INF;
    for(int i = 0; i < n; i++) vv[i] = v[i];

    queue<int> rest;
    priority_queue<ti,vti> pq;
    for(int i = 0; i < n; i++)
        if(v[i]) pq.emplace(v[i],INF,i);

    //cout << " K = " << k << endl;

    for(int i = 0; i < n; i++) {
        if(pq.empty()) return false;
        int pos;
        tie(ignore,ignore,pos) = pq.top();
        pq.pop();

        //cout << pos+1 << " " << last[pos] << " " << i << endl;

        if(last[pos]+k >= i) return false;
        last[pos] = i;

        vv[pos]--;
        if(vv[pos]) rest.push(pos);

        if(i >= k and (!rest.empty())) {
            int ok = rest.front();
            if(last[ok]+k < i+1) {
                pq.emplace(vv[ok],-last[ok],ok);
                rest.pop();
            }
        }
    }

    //cout << " ---------------- " << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) v[i] = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x--;
            v[x]++;
        }

        int l = 0;
        int r = n-1;
        int ans = 0;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        cout << (ans) << endl;
    }

    return 0;
}
