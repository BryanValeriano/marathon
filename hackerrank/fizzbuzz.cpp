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

void fizzbuzz(int n) {
  bool multiple = false;

  for(int i = 1; i <= n; i++) {
    if(i%3 == 0) {
      multiple = true;
      cout << "Fizz";
    }
    if(i%5 == 0) {
      multiple = true;
      cout << "Buzz";
    }
    if(!multiple) cout << i;
    multiple = false;
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  fizzbuzz(n);
  return 0;
}

