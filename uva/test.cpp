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

    int ans = 100;
    
    for(int i = 1; i <= 100; i++) 
        if(i % 2 and i % 5 and i % 8 and i % 30 and i % 7) ans--; 

    cout << 100-ans << endl;

    return 0;
}

