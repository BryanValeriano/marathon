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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int n,k;
string s,t;

int small(int x) {
    if(x > k) return 2;
    int ans = 0;
    char c = s[x];
    int pos = x;

    while(pos < n) {
        ans |= (c < s[pos]);
        if(c > s[pos] and !ans) ans = 2;
        t[pos] = c;
        pos += k;
    }

    return ans;
}

void doIt(int x, char c) { while(x < n) t[x] = c, x += k; }

bool big(int x, int lim) {
    bool ans = 0;
    int pos = x;
    char z = 'x';

    for(char c = s[x]; c <= '9' and z == 'x'; c++) {
        bool a = 0, b = 0;
        pos = x;
        while(pos < lim) {
            a |= (c < s[pos]);
            b |= (c > s[pos]);
            if(a) break;
            if(b) {
                z = c;
                break;
            }
            pos += k;
        }
    }

    if(z == 'x') return 0;
    doIt(x,z);
    return 1;
}

int get() {
    for(int i = 0; i < n; i++)
        if(t[i] < s[i]) return i;
    return n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;

    t = s;

    int i = 0;
    while(i < k and !small(i)) i++;
    int ok = small(i);
    int j = i+1;

    if(ok != 2) {
        int lim = get();
        if(j < k and !big(j,lim)) j++;
        if(j==k) big(i,n), j = i;
        j++;
    }

    while(j < k) doIt(j++,'0');
    cout << n << endl;
    cout << t << endl;

    return 0;
}

