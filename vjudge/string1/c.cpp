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
const int T = 1e6 + 5;

string s;
int z[T];

bool check(int x) {
    int n = s.size();
    for(int i = 0; i < x; i++) {
        if(s[i] != s[n-x+i]) return 0;
    }
    return 1;
}

void ze() {
    int l = 0, r = 0;
    int n = s.size();
    int b = 0, c = 0;

    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(z[i] +i < n and s[z[i] + i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i + z[i] - 1;
        if(i + z[i] == n and z[i] > c) c = max(c,z[i]);
        else if(z[i]) b = max(b,z[i]);
    }

    int x = min(b,c);

    if(x and check(x)) {
        for(int i = 0; i < x; i++) cout << s[i];
        cout << endl;
    } else cout << "Just a legend" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    ze();
    return 0;
}

