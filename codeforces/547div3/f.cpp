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

const int T = 1e5 + 10;

int v[T];
map<int, vector< ii > > track;

bool noOver(auto a, auto b) {
    if(a.se <= b.fi or b.se <= a.fi or a.fi == b.fi or a.se == b.se) return false
    return true;
}



void overlap() {
    ii best;
    int size;
    for(auto x : track) {
        for(auto y : x) {
            int tmpSize = 0;
            for(auto z : x) {
                if(noOver(y,z)) tmpSize++;
            }
            if(tmpSize > size) {
                size = tmpSize;
                best = y;
            }
        }
    }
    delOver(best);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }

    for(int i = 1; i <= n; i++) 
        for(int j = i; j <= n; j++) {
            int sum = v[j] - v[i-1];
            track[sum].eb(i,j);
        }

    overlap();

    int best = 0;
    int sum = 0;
    for(auto x : track) 
        if(x.se.size() > best) best = x.se.size(), sum = x.fi;

    cout << track[sum].size() << endl;
    for(auto x : track[sum]) cout << x.fi << " " << x.se << endl;

    return 0;
}

