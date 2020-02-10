#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 5;
int v[T];
int last[T];
int freq[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int ans = T;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(freq[v[i]]) ans = min(ans,i-last[v[i]]+1);
            freq[v[i]]++;
            last[v[i]] = i;
        }
        for(int i = 0; i < n; i++) freq[v[i]] = last[v[i]] = 0;
        cout << (ans == T? -1 : ans) << endl;
    }



    return 0;
}

