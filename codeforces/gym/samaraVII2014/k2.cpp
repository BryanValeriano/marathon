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
const int T = 1e5 + 10; 
const int N = 1e6;

int v[T], v2[T], q[T], q2[T], mini[N], mini2[N];
vector<int> bag;
unordered_map<int,int> ind;

int main() {
    ios::sync_with_stdio(false);

    memset(mini, INF, sizeof mini);
    memset(mini2, INF, sizeof mini2);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i], bag.pb(v[i]);
    for(int i = 0; i < n; i++) cin >> v2[i], bag.pb(v2[i]);

    int qe; cin >> qe;
    for(int i = 0; i < qe; i++) cin >> q[i], bag.pb(q[i]);
    for(int i = 0; i < qe; i++) cin >> q2[i], bag.pb(q2[i]);

    sort(bag.begin(), bag.end());
    bag.resize(unique(bag.begin(), bag.end()) - bag.begin());
    for(int i = 0; i < bag.size(); i++) ind[bag[i]] = i+1;

    for(int i = 0; i < n; i++) {
        mini[ind[v[i]]] = min(mini[ind[v[i]]], i);    
        mini2[ind[v2[i]]] = min(mini2[ind[v2[i]]], i);    
    }

    for(int i = N-2; i >= 0; i--) {
        mini[i] = min(mini[i], mini[i+1]);
        mini2[i] = min(mini2[i], mini2[i+1]);
    }

    for(int i = 0; i < qe; i++) {
        if(mini[ind[q[i]]+1] < mini2[ind[q2[i]]+1]) cout << "Mike" << endl;
        else if(mini[ind[q[i]]+1] > mini2[ind[q2[i]]+1]) cout << "Constantine" << endl;
        else cout << "Draw" << endl;
    }

    return 0;
}

