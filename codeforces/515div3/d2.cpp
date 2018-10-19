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
const int T = 2e5 + 5;
ll row[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
        cin >> row[i];
    ll maxi = m * k;
    int l = 0; 
    ll track = 0;
    int maxobj = 0;
    for(int i = 0; i < n; i++) { 
        if(track + row[i] <= maxi) {
            maxobj = max(maxobj,i - l + 1);
            track += row[i];
        } else {
            while(track + row[i] > maxi) {
                track -= row[l];
                l++;
            }
            track += row[i];
            maxobj = max(maxobj, i - l + 1);
        }
    }
    cout << maxobj << endl;
    return 0;
}

