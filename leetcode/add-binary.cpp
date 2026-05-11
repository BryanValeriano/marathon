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

class Solution {
public:
  // make the two strings have the same size and a leading 0 for a possible
  // carry
  // reverse it to make the less significant bits come first
  void prepareInputVariables(string &a, string &b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) {
      swap(a, b);
    }
    a += "0";
    while (b.length() < a.length()) {
      b += "0";
    }
  }

  // trim excessive 0s and reverse to compensate
  void prepareResultVariable(string &ans) {
    while (ans.length() > 1 && ans[ans.length() - 1] == '0') {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
  }

  pair<int, int> sum(int a, int b, int carryIn) {
    int result = (a + b + carryIn) % 2;
    int carryOut = (a + b + carryIn) / 2;
    return make_pair(result, carryOut);
  }

  string solveSum(string &a, string &b) {
    int result = 0;
    int carryIn = 0;
    int carryOut = 0;
    string ans;
    for (int i = 0; i < a.length(); i++) {
      auto [result, carryOut] = sum(a[i] - '0', b[i] - '0', carryIn);
      carryIn = carryOut;
      ans += to_string(result);
    }
    return ans;
  }

  string addBinary(string a, string b) {
    prepareInputVariables(a, b);
    string ans = solveSum(a, b);
    prepareResultVariable(ans);
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *sol = new Solution();
  cout << sol->addBinary("11", "1") << endl;
  cout << sol->addBinary("1010", "1011") << endl;
  return 0;
}
