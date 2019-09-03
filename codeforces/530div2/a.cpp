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
    int w,h,w1,h1,w2,h2; 
    cin >> w >> h >> w1 >> h1 >> w2 >> h2;

    for(int i = h; i >= 0; i--) {
        w += i;
        if(i == h1) w -= w1;
        else if(i == h2) w -= w2;
        w = max(0,w);
    }

    cout << w << endl;

    return 0;
}

