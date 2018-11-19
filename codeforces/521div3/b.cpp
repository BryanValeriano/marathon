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
    int row[110];
    for(int i = 0; i < n; i++)
        cin >> row[i];
    int i = 0; 
    int last[3] = {0,0,0};
    int ans = 0;
    while(i < n) {
        last[2] = row[i];
        if(last[0] == 1 and last[1] == 0 and last[2] == 1) {
            row[i] = 0;
            i = 0;
            last[0] = last[1] = last[2] = 0;
            ans++;
            continue;
        }
        last[0] = last[1];
        last[1] = last[2];
        i++;
    }
    cout << ans << endl;


    return 0;
}

