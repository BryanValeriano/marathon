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
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >>n >>x;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >>v[i];
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] + v[i-1] <= x) ans++;
    }
    cout <<ans <<endl;
    
    return 0;
}

