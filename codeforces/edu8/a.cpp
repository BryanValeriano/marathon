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

int games(int x) {
    int j = 1;
    while(pow(2,j) <= x) j++;
    return j-1;
}

int main() {
    ios::sync_with_stdio(false);
    int n, b, p;
    cin >> n >> b >> p;

    int tmp = n;
    int jogos = 0;
    while(tmp != 1) {
        int j = games(tmp);
        tmp -= j;
        jogos += j;
    }

    cout << jogos*b*2 + jogos << " " << n*p << endl;

    return 0;
}

