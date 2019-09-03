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
const int T = 1e3 + 10;
vector<ii> track;
bool open[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        track.eb(a,b);
    }
    int abriu = 0;
    for(int i = 0; i < track.size(); i++) {
        int gol = track[i].se;
        for(int j = 0; j < track.size(); j++) {
            if(i == j or open[j]) continue;
            if(gol == track[j].fi) {
                abriu++;
                open[j] = true;
            }
        }
    }
    cout << n - abriu << endl;
    return 0;
}

