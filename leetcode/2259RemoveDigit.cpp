#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

// 556

class Solution {
public:
  string removeDigit(string number, char digit) {
    int last = 0;
    for (int i = 0; i < number.length(); i++) {
      if (number[i] == digit) {
        last = i;
        if (i + 1 < number.length()) {
          if (number[i] < number[i + 1])
            return number.erase(i, 1);
        }
      }
    }
    return number.erase(last, 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  string value;
  char digit;
  cin >> value >> digit;
  Solution *solution = new Solution();
  cout << solution->removeDigit(value, digit) << endl;
  return 0;
}
