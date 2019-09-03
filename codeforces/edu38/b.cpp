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

int n;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(false);
    int a = 1;
    int b = 1e6;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bag.insert(x);
    }

    ll ans1 = 0;
    ll ans2 = 0;

    while(bag.size()) {
        int low = *bag.begin();
        int high = *bag.rbegin();

        if(ans1 + abs(low-a) <= ans2 + abs(b-high)) {
            ans1 += abs(low-a); 
            a = low;
            bag.erase(bag.begin());
        } else {
            ans2 += abs(b-high);
            b = high;
            bag.erase(bag.find(high));
        }
    }

    cout << max(ans1,ans2) << endl;
    return 0;
}

