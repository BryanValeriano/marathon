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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int v[3]; cin >> v[0] >> v[1] >> v[2];
    int x[3] = { v[0], v[1], v[2] };
    sort(v,v+3);
    for(int i = 0; i < 3; i++) cout << v[i] << endl;
    cout << endl;
    for(int i = 0; i < 3; i++) cout << x[i] << endl;
    return 0;
}

