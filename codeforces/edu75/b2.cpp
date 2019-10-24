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

const int T = 50;

int n;
int a,b,vez;
int v[T];
int acum[T];

int ok(int x, int y) {
    if((x&1) and (y&1)) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    string s;
    while(tc--) {
        cin >> n;
        a = b = 0;

        for(int i = 0; i < n; i++) {
            cin >> s;
            v[i] = s.size();
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == '1') a++;
                else b++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x = v[i]/2;
            int y = x + (v[i]&1);
            if(a >= b) {


        }
        
    } 

    return 0;
}

