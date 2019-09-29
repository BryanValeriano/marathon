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

void test(int x) {
    int freq[10];
    int y = x;
    memset(freq,0,sizeof freq);
    while(x) {
        freq[x%10]++;
        if(freq[x%10] > 1) return;
        x /= 10;
    }

    cout << y << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int l,r; cin >> l >> r;

    for(int i = l; i <= r; i++)
        test(i);

    cout << -1 << endl;

    return 0;
}

