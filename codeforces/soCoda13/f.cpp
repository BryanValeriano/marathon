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

string v[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int n; cin >> n;
    int at = 0;
    for(int i = 0; i < 12; i++) if(v[i] == s) at = i;
    cout << v[(at+n)%12] << endl;
    return 0;
}

