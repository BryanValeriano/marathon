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

// s.length() <= 25
// s contains only lower case letters and ( )

class Solution {
public:
  int calculateCharBalance(char c) {
    if (c == '(')
      return 1;
    if (c == ')')
      return -1;
    return 0;
  }

  int minimumRemoval(string &s, int at, int balance,
                     vector<vector<int>> &memo) {
    if (balance < 0) {
      return 100;
    }
    if (at >= s.length()) {
      return (balance == 0 ? 0 : 100);
    }
    int &r = memo[at][balance];
    if (r != -1) {
      return r;
    }

    int newBalance = balance + calculateCharBalance(s[at]);
    int keep = minimumRemoval(s, at + 1, newBalance, memo);
    int skip = minimumRemoval(s, at + 1, balance, memo) + 1;

    return r = min(keep, skip);
  }

  bool impossibleState(int pos, int len, int balance, int k, int removed) {
    if (balance < 0) {
      return true;
    }
    if (balance > len - pos) {
      return true;
    }
    if (removed > k) {
      return true;
    }
    if (removed + (len - pos) < k) {
      return true;
    }
    return false;
  }

  void chooseK(string &s, int at, string &currentState, int balance, int k,
               vector<string> &ans) {
    int removed = at - currentState.length();
    if (impossibleState(at, s.length(), balance, k, removed)) {
      return;
    }
    if (at == s.length()) {
      if (balance == 0 && removed == k) {
        ans.push_back(currentState);
      }
      return;
    }

    // keep
    int keepChar = calculateCharBalance(s[at]);
    currentState.push_back(s[at]);
    chooseK(s, at + 1, currentState, balance + keepChar, k, ans);
    currentState.pop_back();

    // skip
    chooseK(s, at + 1, currentState, balance, k, ans);
  }

  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    vector<vector<int>> memo(27, vector<int>(27, -1));
    int minimum = minimumRemoval(s, 0, 0, memo);
    string currentState = "";
    chooseK(s, 0, currentState, 0, minimum, ans);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution;
  string s = "()())()";
  vector<string> ans = solution->removeInvalidParentheses(s);
  for (string t : ans) {
    cout << t << endl;
  }
  return 0;
}
