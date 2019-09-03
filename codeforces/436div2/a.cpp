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
const int T = 110;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, aux;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        v[aux]++;
    }

    for(int i = 0; i < T; i++) 
        for(int j = i + 1; j < T; j++)  {
            if(v[i] != 0 and v[i] == v[j] and v[i] + v[j] == n) {
                cout << "YES" << endl; cout << i << " " << j << endl;
                return 0;
            }
        }

    cout << "NO" << endl;


    return 0;
}

