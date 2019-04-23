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

const int T = 55;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; 
    cin >> n;

    while(n) {
        int x = 0;
        for(int i = 0; i < n; i++) cin >> v[i];

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++) {
                if(__gcd(v[i],v[j]) == 1) x++;
            }

        n = (n*(n-1))/2;
        double pi = 6*n;
        pi /= (double)x;
        if(x) cout << setprecision(6) << fixed << sqrt(pi) << endl;
        else cout << "No estimate for this data set." << endl;
        cin >> n;
    }

    return 0;
}

