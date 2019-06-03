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

const int T = 4e6;

queue<int> a;
queue<int> b;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n; 
    int k1,k2,x,y;

    cin >> k1;
    for(int i = 0; i < k1; i++) {
        cin >> x;
        a.push(x);
    }

    cin >> k2;
    for(int i = 0; i < k2; i++) {
        cin >> x;
        b.push(x);
    }

    int p = 0;

    while(!a.empty() and !b.empty()) {
        if(p > 1e7) { cout << -1 << endl; return 0; }
        x = a.front(), a.pop();
        y = b.front(), b.pop();
        if(x > y) { 
            a.push(y);
            a.push(x);
        } else {
            b.push(x);
            b.push(y);
        }
        p++;
    }

    cout << p << " " << (a.empty()? 2 : 1) << endl;
    return 0;
}

