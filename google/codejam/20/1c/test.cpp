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
const int T = 1000;
int freq[10];

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i < T; i++) {
        for(int j = 1; j <= i; j++) {
            int x = j;
            while(x) {
                freq[x%10]++;
                x /= 10;
            }
        }
    }
    for(int i = 0; i < 10; i++) cout << i << " " << freq[i] << endl;
    return 0;
}

