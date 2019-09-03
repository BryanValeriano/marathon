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
vector<int>prims;
set<int>mults;
set<int>sums;

bool isprime(int x) {
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

void build() {
    for(int i = 2; i <= 100; i++) 
        if(isprime(i)) prims.pb(i);
    for(int i = 0; i < prims.size(); i++) {
        for(int j = i + 1; j < prims.size(); j++) { 
            int mult = prims[i] * prims[j];
            if(mult <= 200) mults.insert(mult);
        }
    }
    set<int>:: iterator it1;
    set<int>:: iterator tmp;
    set<int>:: iterator it2;
    for(it1 = mults.begin(); it1 != mults.end(); it1++) {
        for(it2 = it1; it2 != mults.end(); it2++) {
            int sum = (*it1) + (*it2);
            if(sum <= 200) sums.insert(sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    build();
    while(tc--) {
        int n; cin >> n;
        cout << (sums.count(n)? "YES" : "NO") << endl; 
    }

    return 0;
}

