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
    string s; cin >> s;
    string t;
    for(int i = 0; i < s.size(); i++) t += '0';

    for(int i = 1; i < s.size(); i++) {
        if(s[i] >= s[i-1] and t[i] >= t[i-1]) continue;
        else t[i-1] = s[i-1]; 
    }

    cout << t << endl;

    return 0;
}

