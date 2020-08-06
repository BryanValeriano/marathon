#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt_rand(seed);

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5;
const int M = 5e5;
set<ii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    cout << T << " " << M << endl;
    for(int i = 1; i <= M; i++) {
        int x = (i%(T+1))+1;
        int y = (mt_rand()%(T+1))+1;
        if(x>y) swap(x,y);
        while(bag.count(mk(x,y))) {
            y = (mt_rand()%(T+1))+1;
            if(x>y) swap(x,y);
        }
        cout << x << " " << y << endl;
    }
    return 0;
}

