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
    int n; cin >> n;
    int aux;
    vector<int>v;
    map<int,ll>track;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        v.pb(aux);
        track[aux]++;
    }
    sort(v.begin(), v.end());
    ll maxi = *v.rbegin() - *v.begin();
    ll vezes;
    if(*v.rbegin() != *v.begin()) vezes = track[*v.rbegin()] * track[*v.begin()];
    else vezes = (track[*v.begin()] * (track[*v.begin()] - 1LL))/2LL;
    cout << maxi << " " << vezes << endl;
    return 0;
}

