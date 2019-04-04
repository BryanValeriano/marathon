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
int v[T];
int track[T];
int n;

bool hasT() {
    for(int i = 0; i < n; i++) {
        track[v[i]]++;
        if(track[v[i]] == 3) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    if(hasT()) { cout << "NO" << endl; return 0; }
    sort(v, v+n);
    vector<int> cresce;
    vector<int> diminui;

    for(int i = 0; i < n; i++) {
        if(i&1) cresce.pb(v[i]);
        else diminui.pb(v[i]);
    }
    reverse(diminui.begin(), diminui.end());
    cout << "YES" << endl;
    cout << cresce.size() << endl;
    for(auto x : cresce) cout << x << " ";
    cout << endl;
    cout << diminui.size() << endl;
    for(auto x : diminui) cout << x << " ";
    cout << endl;


    return 0;
}

