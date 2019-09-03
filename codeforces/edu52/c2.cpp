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
int row[T];

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int aux;
    int maxi = 0;
    int mini = INF;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        row[aux]++;
        maxi = max(maxi, aux);
        mini = min(mini, aux);
    }
    for(int i = maxi-1; i >= 1; i--) 
        row[i] += row[i+1]; 
    int cut = maxi;
    int ans = 0;
    while(cut > mini) {
        int novo = 0; 
        while(novo <= k && cut >= mini) {
            novo += row[cut];
            cut--;
        }
        if(novo > k) cut++;
        ans++;
    }
    cout << ans << endl;

    

    return 0;
}

