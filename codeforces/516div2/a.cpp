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
const int LIM = 1000100;
set<ll> quad;
int a,b,c;

struct node {
    int a,b,c;

    node(int a, int b, int c) :
        a(a), b(b), c(c) {}
};

vector<node> ans;

void test() {
    for(ll i = 1; i <= 100; i++)
        for(ll j = 1; j <= 100; j++)
            for(ll k = 1; k <= 100; k++)
                if(i + j > k and i + k > j and j + k > c) ans.pb(node(i,j,k));
}

int dist(int x, int y, int z) {
    return (abs(a-x) + abs(b-y) + abs(c-z));
}

int solve() {
    int resp = INF;
    for(int i = 0; i < ans.size(); i++) {
        resp = min(resp, dist(ans[i].a, ans[i].b, ans[i].c));
    }

    return resp;
}


int main() {
    ios::sync_with_stdio(false);
    int x[3];
    for(int i = 0; i < 3; i++) cin >> x[i];
    sort(x, x+3);
    a = x[0]; b = x[1]; c = x[2];
    test();
    cout << solve() << endl;
    return 0;
}

