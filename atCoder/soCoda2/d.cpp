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
const int T = 102;

int sum[T];
set<ii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 2; i <= n; i++) {
        sum[i] += 1;
        sum[1] += i;
        bag.emplace(1,i);
    }

    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if(i == j) continue;
            if(bag.count(mk(min(i,j),max(i,j)))) continue;

            if(sum[i] + j <= sum[1] and  sum[j] + i <= sum[1]) {
                bag.emplace(min(i,j),max(i,j));
                sum[i] += j;
                sum[j] += i;
            }
        }
    }

    cout << bag.size() << endl;
    for(auto ok : bag) cout << ok.fi << " " << ok.se << endl;
    for(int i = 1; i <= n; i++) cout << sum[i] << endl;



    return 0;
}

