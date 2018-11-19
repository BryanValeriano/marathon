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


int main() {
    ios::sync_with_stdio(false);
    vector<ll>probs;
    stack<ll> zeros;
    set<ll> ans;
    ll negs = 0;
    ll aux;
    ii neg = ii(-INF,-INF);
    ll n; cin >> n;
    for(int i = 1; i <= n; i++) {
        ans.insert(i);
        cin >> aux;
        if(aux == 0) zeros.push(i);
        else if(aux < 0) {
            negs++;
            if(aux > neg.fi) neg = ii(aux,i);
        }
    }
    bool flag = true;
    if(negs % 2 != 0 and zeros.size() != 0) {
        cout << 1 << " " <<  neg.se << " " << zeros.top() << endl;
        ans.erase(neg.se);
        negs--;
        n--;
    }
    else if(negs % 2 != 0) {
        cout << 2 << " " << neg.se << endl;
        ans.erase(neg.se); 
        flag = false;
    }
    if(zeros.size() > 0 && zeros.size() != n && flag) {
        while(zeros.size() > 1) {
            cout << 1 << " " << zeros.top() << " ";
            ans.erase(zeros.top());
            zeros.pop();
            cout << zeros.top() << endl;
        }
        cout << 2 << " " << zeros.top() << endl;
        ans.erase(zeros.top());
    }
    ll last = *ans.begin();
    for(auto r : ans) {
        if(r == *ans.begin()) continue; 
        cout << 1 << " " << last << " " << r << endl; 
        last = r;
    }

    return 0;
}

