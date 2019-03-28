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

string s;
int n;

int count() {
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '<') a = 1;
        if(s[i] == '>') b = 1;
    }
    return a+b;
}

int Bponta() {
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '>') break;
        a++;
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '<') break;
        b++;
    }
    return min(a,b);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> s;
        if(s.size() >= 2 and count() == 2) cout << Bponta() << endl;
        else cout << 0 << endl;
    }
    return 0;
}

