#include <bits/stdc++.h>
using namespace std;

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

struct Node {
    int x, y, color;
};

typedef tuple<int, int, int> tup;

void readInput(int& n, int& b, int& r, vii& coord) {
  cin >> n >> b >> r;
  int a, b;
  for (int i = 0;i < b + r;i++) {
    cin >> a >> b;
    coord.emplace_back(a, b);
  }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, b, r;
    vector<ii> coords;
    readInput(n, b, r, coords);


    return 0;
}#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    return 0;
}

