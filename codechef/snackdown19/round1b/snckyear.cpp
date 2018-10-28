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
    ios_base::sync_with_stdio(false);
    set<int>year;
    year.insert(2010);
    year.insert(2015);
    year.insert(2016);
    year.insert(2017);
    year.insert(2019);
    int q; cin >> q;
    while(q--) {
        int aux; cin >> aux;
        cout << (year.count(aux)? "HOSTED" : "NOT HOSTED") << endl;
    }
    return 0;
}

