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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        string s1,s2; cin >> s1 >> s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int a = INF;
        int b = INF;

        for(int i = 0; i < s2.size(); i++)
            if(s2[i] == '1') { b = i; break; }
        for(int i = b; i < s1.size(); i++)
            if(s1[i] == '1') { a = i; break; }

        if(b == INF) cout << 0 << endl;
        else cout << (a-b) << endl;
    }


    return 0;
}

