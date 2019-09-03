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
const int T = 500 + 2;
int row[T];
int n, k;

bool test(ll tent) {
    int scrib = 1;
    ll cary = 0;
    for(int i = 0; i < n; i++) {
        if(scrib > k or cary > tent) return false;
        if(cary + row[i] <= tent) 
            cary += row[i];
        else { scrib++; cary = row[i]; }
    }
    return (scrib > k or cary > tent? false : true);
}

void print(ll tent) {
    int scrib = k-1;
    ll cary = 0;
    stack<int>resp;
    for(int i = n-1; i >= 0; i--) {
        if(cary + row[i] <= tent and scrib <= i) {
            cary += row[i]; 
            resp.push(row[i]);
        } else {
            scrib--;
            cary = row[i];
            resp.push(-1);
            resp.push(row[i]);
        }
    }
    while(!resp.empty()) {        
        ll x = resp.top();
        resp.pop();
        if(x == -1) cout << "/";
        else cout << x;
        cout << (resp.empty()? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        ll lo = 1;
        ll hi = 0;
        for(int i = 0; i < n; i++) {
            cin >> row[i];
            hi += row[i];
        }
        ll mid = (lo+hi)>>1;
        for(int times = 0; times < 100; times++) {
            mid = (lo+hi)>>1;
            if(test(mid)) hi = mid;
            else lo = mid+1;
        }
        print(lo);
    }

    return 0;
}

