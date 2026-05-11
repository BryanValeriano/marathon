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

// 1 1 1 1
// 11 1 1
// 1 11 1
// 1 1 11
// 11 11

class Solution {
public:
  bool isValid(string s) {
    if (s[0] == '0')
      return false;
    int x = stoi(s);
    return x >= 1 && x <= 26;
  }

  int numDecodings(string s) {
    vector<long long> memo(s.size() + 2, 0);
    if (s[0] == '0') {
      return 0;
    }
    memo[0] = 1;
    for (int i = 1; i < s.length(); i++) {
      // just this char
      string justThisChar = s.substr(i - 1, 2);
      memo[i] += isValid(justThisChar) ? memo[i - 1] : 0;
      // combine with last
      string combineWithLast = s.substr(i - 1, 2);
      if (isValid(combineWithLast)) {
        memo[i] += i > 1 ? memo[i - 2] : 1;
      }
    }
    return memo[s.length() - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution;
  cout << solution->numDecodings("12") << endl;
  cout << solution->numDecodings("226") << endl;
  cout << solution->numDecodings("1111") << endl;
  return 0;
}
