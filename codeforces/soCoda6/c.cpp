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

string f(int x) {
    if(x == 0) return "0";
    if(x == 1) return "1";
    return f(x-1) + f(x-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << f(4) << endl;



    return 0;
}

