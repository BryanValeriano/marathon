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

int main() {
    ios::sync_with_stdio(false);
    string s,r;
    cin >> s >> r;
    int i = 0;
    int j = 0;

    while(i < s.size() and j < r.size()) {
        if(s[i] == r[j])j++;
        i++;
    }
    cout << (j == r.size()? "YES" : "NO") << endl;
    return 0;
}

