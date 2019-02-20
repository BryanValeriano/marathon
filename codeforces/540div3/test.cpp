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
const int n = 18;
int freq[500];

int main() {
    ios::sync_with_stdio(false);
    cout << n << endl;
    for(int i = 0; i < n*n; i++) {
        cout << (i%9)+1 << " ";
        freq[(i%9)+1]++;
    }

    cout << endl;
    //for(int i = 1; i <= 9; i++) cout << i << " " << freq[i] << endl;

    return 0;
}

