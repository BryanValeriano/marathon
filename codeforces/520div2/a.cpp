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

bool cmp(const int &a ,const int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int row[n+10];
    int row2[n+10];
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> row2[i];
        row[i] = row2[i] - (i - 1 >= 0? row2[i-1] : 0);
    }
    vector<int>ans;
    ans.pb(0);
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(row[i] == 1 and i + 1 != n and row[i+1] != 1) {
            ans.pb(cont);
            cont = 0;
            continue; 
        }
        if(1000 - row2[i] == (n-1) - i) { 
            cont += (n-1) - i;
            ans.pb(cont);     
            break; 
        }
        if(row[i] == 1 and i == n-1) ans.pb(cont);
        else if(row[i] == 1)cont++;

    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0] << endl;

    return 0;
}

