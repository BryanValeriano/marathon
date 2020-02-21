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

void print(const vector<int> &v) {
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int k; cin >> k;
    int x = 0;
    
    do {
        x++;
        if(x == k) print(v);
    } while(next_permutation(v.begin(),v.end()));

    
    
    return 0;
}

