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
    int n; string s;
    cin >> n >> s;
    int sum1, sum2;
    sum1 = sum2 = 0;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != '7' and s[i] != '4') { cout << "NO" << endl; return 0; }
        else sum1 += s[i] - '0';
    }
    for(int i = n/2; i < n; i++) {
        if(s[i] != '7' and s[i] != '4') { cout << "NO" << endl; return 0; }
        else sum2 += s[i] - '0';
    }
    cout << (sum1 == sum2? "YES" : "NO") << endl;

    return 0;
}

