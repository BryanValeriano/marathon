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
    int n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    int ta,fa,tb,fb;
    while(k--) {
        cin >> ta >> fa >> tb >> fb;
        int ans = 0; 
        if(ta != tb) {
            ans += abs(ta - tb);
            if(fa > b) {
                ans += abs(fa - b);
                ans += abs(fb - b);
            }
            else if(fa < a) {
                ans += abs(fa - a);
                ans += abs(fb - a);
            } else {
                ans += abs(fa - fb);
            }
        } else {
            ans += abs(fa - fb);
        } cout << ans << endl;
    }
    return 0;
}

