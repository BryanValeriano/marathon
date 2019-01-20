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
vector<int> v;
int morto[T];


int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        v.pb(aux);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int low = lower_bound(v.begin(), v.end(), v[i] - k) - v.begin();
        int corner = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
        if(low == i or v[low] + k < v[i]) continue;
        if(corner - 1 >= 0) morto[corner-1]++;
        if(low-1 >= 0) morto[low-1]--;
        //cout << v[i] << " " << v[low] << endl;
    }
    
    for(int i = v.size() - 1; i >= 0; i--) morto[i] += morto[i+1]; 
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        if(morto[i]) ans++;
        //cout << morto[i] << " ";
    } 
    //cout << endl;
    cout << n - ans << endl;
        
        

    return 0;
}

