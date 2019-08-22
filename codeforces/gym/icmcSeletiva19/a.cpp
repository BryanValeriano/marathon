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

const int T = 1e5 + 1500;
const int root = sqrt(T);
int bucket[root+2];
int v[T];
int n;

int query(int at) {
    int ans = 0;
    int alt = v[at];
    int pos = at/root;

    while(pos <= root and alt >= bucket[pos] and (pos*root) - at <= alt) pos++;

    int nat = max(pos*root, at);
    while(nat <= n and alt >= v[nat]) nat++;

    return min((nat-at)-1,alt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        bucket[i/root] = max(bucket[i/root],v[i]);
    }

    bucket[(n-1)/root] = INF;
    v[n] = INF;

    for(int i = 0; i < n; i++)
        cout << query(i) << " ";
    cout << endl;

    return 0;
}

