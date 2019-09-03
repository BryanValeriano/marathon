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
int tmp[27];

int main() {
    ios::sync_with_stdio(false);
    sting s; cin >> s;
    for(int i = 0; i < s.size(); i++)
        tmp[s[i] - 'a']++;
    int odd = 0;
    for(int i = 0; i < 27; i++) 
        if(tmp[i] % 2 != 0) odd++;
    if(odd > 1) {
        


    return 0;
}

