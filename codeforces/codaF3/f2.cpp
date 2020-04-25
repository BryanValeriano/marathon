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
const int T = 1e5 + 3;
int ans[T], v[T];
int qtd, dist = -1, back;

int main() {
    ios_base::sync_with_stdio(false);
    multiset<int> bag;

    int n,k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        bag.insert(v[i]);
        while(*bag.rbegin()-*bag.begin() > k) bag.erase(bag.find(v[back++]));
        if(i-back+1 == dist) ans[++qtd] = back+1;
        if(i-back+1 > dist) {
            dist = i-back+1;
            ans[qtd=0] = back+1;
        }
    }

    cout << dist << " " << qtd+1 << endl;
    for(int i = 0; i <= qtd; i++)
        cout << ans[i] << " " << ans[i]+dist-1 << endl;

    return 0;
}

