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
    int v[n];
    int m; cin >> m;
    ii mini = ii(INF,INF);
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(mini.fi > v[i]) mini = ii(v[i],i);
        maxi = max(maxi,v[i]);
    }
    int tem = m;
    for(int i = 0; i < m; i++) {
        v[mini.se] += 1;
        tem--;
        mini.fi = INF;
        for(int j = 0; j < n; j++) 
            if(mini.fi > v[j]) mini = ii(v[j],j);
    }
    for(int i = 0; i < n; i++) 
        if(mini.fi < v[i]) mini = ii(v[i],i);
   
    cout << mini.fi << " ";
    cout << maxi + m << endl;

    return 0;
}

