#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 3e5 + 3;
int prox[T];

struct node {
    int f,s,id;

    node(int f, int s, int id) :
        f(f), s(s), id(id) {}

};

vector<node> v1;
vector<node> v2;

int n;

bool cmp1(const node &a, const node &b) {
    return a.s > b.s;
}

bool cmp2(const node &a, const node &b) {
    return a.s < b.s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    int x,y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if(x < y) v1.pb({x,y,i+1});
        else if(x > y) v2.pb({x,y,i+1});
    }

    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp2);

    if(v1.size() >= v2.size()) {
        cout << v1.size() << endl;
        for(auto ok : v1) cout << ok.id << " ";
        cout << endl;
    } else {
        cout << v2.size() << endl;
        for(auto ok : v2) cout << ok.id << " ";
        cout << endl;
    }
    return 0;
}

