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
    int n,k;
    cin >> n >> k;
    map<int,int> freq;
    vector<int> v(n);
    set<int> bag;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        freq[v[i]]++;
        if(freq[v[i]]==1) bag.insert(v[i]);
        else bag.erase(v[i]);
        if(i >= k) {
            freq[v[i-k]]--;
            if(freq[v[i-k]]==1) bag.insert(v[i-k]);
            else bag.erase(v[i-k]);
        }
        if(i+1 >= k) {
            if(bag.empty()) cout << "Nothing\n";
            else cout << *bag.rbegin() << endl;
        }
    }
    return 0;
}

