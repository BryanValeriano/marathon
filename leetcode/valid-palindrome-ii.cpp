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
  bool isPalindromeWithOneSkip(string &s, bool skipLeft) {
    int l = 0;
    int r = s.length() - 1;
    bool skipped = false;
    while (l < r) {
      if (s[l] != s[r]) {
        if (skipped) {
          return false;
        }
        skipped = true;
        l += skipLeft;
        r -= !skipLeft;
      } else {
        l++;
        r--;
      }
    }
    return true;
  }

  bool validPalindrome(string s) {
    if (isPalindromeWithOneSkip(s, false)) {
      return true;
    }
    if (isPalindromeWithOneSkip(s, true)) {
      return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *sol = new Solution();
  cout << (sol->validPalindrome("aba") ? "true" : "false") << endl;
  cout << (sol->validPalindrome("abca") ? "true" : "false") << endl;
  cout << (sol->validPalindrome("abc") ? "true" : "false") << endl;
  return 0;
}
